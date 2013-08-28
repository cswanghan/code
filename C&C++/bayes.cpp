


bool NaiveBayes::Train (const char * sFileSample, int iClassNum, int iFeaTypeNum, string & sSegmenter, int iFeaExtractNum, const char * sFileModel, bool bCompactModel)
{
	// �����Դ���
	if (iClassNum <= 0 || iFeaTypeNum <= 0 || iFeaExtractNum <= 0)
		return false;

	ifstream in (sFileSample, ios_base::binary);
	ofstream out (sFileModel);
	if (!in || !out)
	{
		cerr << "Can not open the file" << endl;
		return false;
	}

	// ��Щ������ʱ���ݽṹ��������ʱ�洢ģ�Ͳ���������ѡ����Ҫ�Ĳ����ȵ�
	// 1. the temp data structure for model parameters ģ�Ͳ�������ʱ���ݽṹ
	// 1.1 the total number of document in training samples  ѵ���������ļ�����
	int iTotalDocNum = 0;
	// 1.2 the prior probability of class, temparaly it store the doc number in this class  
	double * pClassPriorProb = new double [iClassNum];
	memset (pClassPriorProb, 0, iClassNum*sizeof(double));
	// 1.3 the prior probability of feature type, temparaly it stores the doc number in this feature �������Ҫ��������ѡ��bayesģ�ͱ�������Ҫ���������
	double * pFeaItemPriorProb = new double [iFeaTypeNum];
	memset (pFeaItemPriorProb, 0, iFeaTypeNum*sizeof(double));
	// 1.4 the chi-square value that feature falls into class, temparaly it stores the doc number for this class and feature �����Կ���������ѡ���㷨��Ҫ�ÿ���ѡ��
	double ** ppChiMatrix = new double * [iClassNum];
	for (int i=0; i<iClassNum; i++)
	{
		ppChiMatrix[i] = new double [iFeaTypeNum];
		memset (ppChiMatrix[i], 0, iFeaTypeNum*sizeof(double));
	}
	// 1.5 the post-probability for class and feature
	double ** ppPProbMatrix = new double * [iClassNum];
	for (int i=0; i<iClassNum; i++)
	{
		ppPProbMatrix[i] = new double [iFeaTypeNum];
		memset (ppChiMatrix[i], 0, iFeaTypeNum*sizeof(double));
	}
	// 1.6 for the feature selection ����ʾ��Щ������ѡ���ˣ�
	int * pFeaSelected = new int [iFeaTypeNum];
	memset (pFeaSelected, 0, iFeaTypeNum*sizeof(int));

	// 2. iterate the training samples and fill count into the temp data structure
	string sLine;
	int i = 0;
	while (getline (in, sLine))
	{
		// show some information on screen
		if (0 == i%10000)
			cout << i << "\n";
		i++;

		// 2.1 the total number of doc
		iTotalDocNum++;

		// 2.2 split the sample into class and feature items
		string::size_type iSeg = sLine.find_first_of (sSegmenter);
		string sTmp = sLine.substr (0, iSeg);
		int iClassId = atoi (sTmp.c_str());
		if (iClassId >= iClassNum)
			continue;
		pClassPriorProb [iClassId]++;

		// 2.3 count the rest feature items
		iSeg += sTmp.length();
		sTmp = sLine.substr (iSeg);
		istringstream isLine (sTmp);
		string sTmpItem;
		while (isLine >> sTmpItem)
		{
			int iFeaItemId = atoi (sTmpItem.c_str());
			if (iFeaItemId >= iFeaTypeNum)
				continue;
			// add the count
			pFeaItemPriorProb [iFeaItemId]++;
			ppChiMatrix [iClassId][iFeaItemId]++;

		}
	}

	// 3. calculate the model parameters 
	// 3.1 the chi-square value as well as the post-probabilty
	for (int i=0; i<iClassNum; i++)
	{
		for (int j=0; j<iFeaTypeNum; j++)
		{
			double dA = ppChiMatrix[i][j];
			double dB = pFeaItemPriorProb[j] - dA; // currently pFeaItemPriorProb[i] == sum_i (ppChiMatrix[i][j])
			double dC = pClassPriorProb [i] - dA;  // currently pClassPriorProb[i] == sum_j (ppChiMatrix[i][j])
			double dD = (double)iTotalDocNum - dA - dB - dC;

			// the chi value 
			double dNumerator = dA * dD;
			dNumerator -= dB * dC;
			dNumerator = pow (dNumerator, 2.0);
			double dDenominator = dA + dB;
			dDenominator *= (dC + dD);
			dDenominator += DBL_MIN; // for smoothing
			ppChiMatrix[i][j] = dNumerator / dDenominator;

			// the post-probability: p(feature|class)
			ppPProbMatrix[i][j] = dA / pClassPriorProb [i];
		}
	}

	// 3.2 the prior probability of class
	for (int i=0; i<iClassNum; i++)
		pClassPriorProb [i] /= iTotalDocNum;

	// 3.3 the prior probability of feature
	for (int i=0; i<iFeaTypeNum; i++)
		pFeaItemPriorProb [i] /= iTotalDocNum;


	// 4. feature selection �����������һƪ��������ϸ����
	FeaSelByChiSquare (ppChiMatrix, ppPProbMatrix, iClassNum, 
		iFeaTypeNum, iFeaExtractNum, pFeaSelected);

	// 5. dump the model into txt file

	if (bCompactModel)		// output the parameters only for predicting
	{
		// 5.1 the prior probability of class
		out << iClassNum << endl;
		for (int i=0; i<iClassNum; i++)
		{
			out << pClassPriorProb [i] << "\n";
		}
		// 5.2 the actual selected feature type number
		int iActualFeaNum = 0;
		for (int j=0; j<iFeaTypeNum; j++)
		{
			if (1 == pFeaSelected[j])
				iActualFeaNum ++;
		}
		out << iActualFeaNum << endl;
		// 5.3 the post probability
		for (int i=0; i<iClassNum; i++)
		{
			for (int j=0; j<iFeaTypeNum; j++)
			{
				if (1 == pFeaSelected[j])
				{
					out << j << ":" << ppPProbMatrix[i][j] << "\n";
				}
			}
		}
	}
	else					// output the full information
	{
		// 5.1 the total number of document
		out << iTotalDocNum << endl;

		// 5.2 the prior probability of class 
		out << iClassNum << endl;
		for (int i=0; i<iClassNum; i++)		// classindex:priorprob
		{
			out << i << ":" << pClassPriorProb [i] << "\n";
		}

		// 5.3 the prior probability of feature type: this is NO used in bayes model, record this for more info
		//     and whether this feature is selected or not by any class
		out << iFeaTypeNum << "\n";
		for (int i=0; i<iFeaTypeNum; i++)	// featureId:priorprob:selected or not
		{
			out << i << ":" << pFeaItemPriorProb[i] << ":" << pFeaSelected << "\n";
		}

		// 5.4 the chi-square value for class-feature pair
		for (int i=0; i<iClassNum; i++)
		{
			for (int j=0; j<iFeaTypeNum; j++)
			{
				out << ppChiMatrix[i][j] << "\n";
			}
		}

		// 5.5 the post probability 
		for (int i=0; i<iClassNum; i++)
		{
			for (int j=0; j<iFeaTypeNum; j++)
			{
				out << ppPProbMatrix[i][j] << "\n";
			}
		} 
	}

	// last, release the memory
	delete [] pClassPriorProb;
	delete [] pFeaItemPriorProb;
	for (int i=0; i<iClassNum; i++)
	{
		delete [] ppChiMatrix[i];
	}
	delete [] ppChiMatrix;
	for (int i=0; i<iClassNum; i++)
	{
		delete [] ppPProbMatrix[i];
	}
	delete [] ppPProbMatrix;
	delete [] pFeaSelected;

	return true;
}



�������������Ҫ���ܾ���ͳ�ƣ�һ����ͳ�ƺ�����ʣ���һ����ͳ�ƿ�������ѡ������Ҫ�Ĳ��������Ƿֱ�洢��ppChiMaxtrix��ppProbMatrix�����������Ƕ�ά���飬�����ά���������Ŀ�����������������������ݽṹ����Ʒ����c�ķ���Լ�����ݣ��������ͷţ���û����c++ stl�еĸ������ݽṹ���磺set��map�ȡ��м侭������ѡ�����ģ�ʹ洢���ı��ļ����С�




��������������ѡ���㷨��




