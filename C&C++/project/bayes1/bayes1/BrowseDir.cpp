#include<iostream>
#include<direct.h>
#include<string.h>
#include<io.h>
#include<stdio.h>
#include<fstream>

#include"CBrowseDir.h"

static int Flag = 0; //ͳ���ļ���Ŀ
static int Flagtemp = 0;
static int Wordline = 0; //ͳ�ƴʿ��еĴ�����Ŀ
static int ObjectCnt = 0;


#if 1

CBrowseDir::CBrowseDir()
{
	GetSignal();
	int len = 0;
	Flagtemp = Flag;
	ClassCnt++;
	m_StopWordNum = ReadStopList("StopWord.dat");

	if(m_switch == 0){
	
		switch(ObjectCnt){
		
		case 0:
			getcwd(m_szInitDir,_MAX_PATH);
			//���Ŀ¼�����һ����ĸ����'\'������������һ��'\'
			len = strlen(m_szInitDir);
			if(m_szInitDir[len-1] != '\\')
				strcat(m_szInitDir,'\\');
			memset(RestoreFileName,0,strlen(RestoreFileName));
			strcpy(RestoreFileName,Path);
			strcat(RestoreFileName,"Spam_data1.dat");
			break;
		case 1:
			getcwd(m_szInitDir,_MAX_PATH);
			len = strlen(m_szInitDir);
			if(m_szInitDir[len-1] != '\\')
				strcat(m_szInitDir,"\\");
			memset(RestoreFileName,0,strlen(RestoreFileName));
			strcpy(RestoreFileName,Path);

			strcat(RestoreFileName,"Normal_data2.dat");
			break;
		case 2:
			strcpy(m_szInitDir,Path);
			//���Ŀ¼�����һ����ĸ����'\'������������һ��'\'
			len = strlen(m_szInitDir);
			if(m_szInitDir[len-1] != '\\')
				strcat(m_szInitDir,'\\');
			cout<<"Route" <<endl;
			break;
		default:
			break;
		}
	   ObjectCnt++;
	}else if(m_switch == 1)
	{
		strcpy(m_szInitDir,Path);
		//���Ŀ¼�����һ����ĸ����'\'������������һ��'\'
		len = strlen(m_szInitDir);
		if(m_szInitDir[len-1] != '\\')
			strcat(m_szInitDir,'\\');
		cout<<"Route"<<endl;
	}
	m_nFileCount = 0;
	m_nSubdirCount = 0;

}

#endif

bool CBrowseDir::SetInitDir(const char *dir)
{
	//�Ȱ�dirת���ɾ���·��
	if(_fullpath(m_szInitDir,dir,_MAX_PATH) == NULL)
		return false;

	//�ж�Ŀ¼�Ƿ����
	if(_chdir(m_szInitDir) != 0)
		return false;

	//���Ŀ¼�����һ����ĸ����'\'������������һ��'\'
	int len = strlen(m_szInitDir);
	if(m_szInitDir[len-1] != '\\')
		strcat(m_szInitDir,'\\');

	return true;
}

bool CBrowseDir::BeginBrowse(const char *filespec)
{
	ProcessDir(m_szInitDir,NULL);
	return BrowseDir(m_szInitDir,filespec);
}

bool CBrowseDir::BrowseDir(const char *dir,const char *filespec)
{
	_chdir(dir);

	long hFile;
	_finddata_t fileinfo;
	if((hFile = _findfirst(filespec,&fileinfo))!= -1)
	{
		do{
			if(!(fileinfo.attrib & _A_SUBDIR))
			{
				char filename[_MAX_PATH];
				strcpy(filename,dir);
				strcpy(FName,Restore);
				int len = strlen(FName);
				if(FName[len-1] != '\\')
					strcat(FName,'\\');

				strcat(FName,&filename[3]);
				CreateDir(FName);  //�����µ�Ŀ¼

				strcat(filename,fileinfo.name);
				strcpy(tempFName,fileinfo.name);
				strcat(FName,fileinfo.name);

				if(!ProcessFile(filename))
					return false;
			}

		}while(_findnext(hFile,&fileinfo) == 0);

		_findclose(hFile);
	}


	_chdir(dir);
	if((hFile = _findfirst("*.*",&fileinfo)) != -1 )
	{

	}


}