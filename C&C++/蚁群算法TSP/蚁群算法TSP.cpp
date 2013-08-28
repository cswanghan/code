// ��Ⱥ�㷨TSP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<time.h>
#include <stdlib.h>
#include<cmath>
#include <tchar.h>
using namespace std;

const int N_CITY_COUNT=51; //��������
const int N_ANT_COUNT=20; //��������
const int N_IT_COUNT=10000; //��������

//��Ⱥ�㷨����
const double ALPHA=1.0;
const double BETA=2.0;
const double ROU=0.98; //��Ϣ�ز���ϵ����(1-ROU)������Ϣ�صĻӷ��ٶ�
const double Pbest=0.05; //����һ�������ҵ�����·���ĸ���

const double DBQ=100.0; //�ܵ���Ϣ��
const double DB_MAX=10e9; //һ����־��
double g_Trial[N_CITY_COUNT][N_CITY_COUNT]; //�������м���Ϣ��
double g_Distance[N_CITY_COUNT][N_CITY_COUNT]; //�������м����

double g_Prob[N_CITY_COUNT][N_CITY_COUNT];
double g_DistanceBeta[N_CITY_COUNT][N_CITY_COUNT];

int rnd(int nLow,int nUpper); //���������
double rnd(double dbLow,double dbUpper);
double ROUND(double dbA);

double x_Ary[N_CITY_COUNT];
double y_Ary[N_CITY_COUNT];

struct ant
{
    int m_nPath[N_CITY_COUNT]; //�����ߵ�·��
	double m_dbPathLength; //�����߹���·������

	int m_nAllowedCity[N_CITY_COUNT]; //ûȥ���ĳ���
	int m_nCurCityNo; //��ǰ���ڳ��б��
	int m_nMovedCityCount; //�Ѿ�ȥ���ĳ�������

	bool m_blGreedSearch; //�Ƿ�ʹ��̰��ԭ��ѡ����һ����
}a[N_ANT_COUNT];

struct tsp{
    ant m_cAntAry[N_ANT_COUNT];
	ant m_cBestAnt; //������
	double m_dbRate; //�����Ϣ�غ���С��Ϣ�صı�ֵ

}T;

    int ChooseNextCity(); //ѡ����һ������
	int GreedChooseNextCity(); //̰��ԭ��ѡ����һ������

	void ant_Init(); //��ʼ��
	void ant_Move(); //�����ڳ��м��ƶ�
	void ant_Search(); //����·��
	void CalPathLength(); //���������߹���·������
	void tsp_InitData(); //��ʼ������
	void tsp_Search(); //��ʼ����
	void tsp_UpdateTrial();//���»�����Ϣ��


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
//eil51.tsp������������
double  x_Ary[N_CITY_COUNT]=
{
	37,49,52,20,40,21,17,31,52,51,
	42,31,5,12,36,52,27,17,13,57,
	62,42,16,8,7,27,30,43,58,58,
	37,38,46,61,62,63,32,45,59,5,
	10,21,5,30,39,32,25,25,48,56,
	30
};

double y_Ary[N_CITY_COUNT]=
{
	52,49,64,26,30,47,63,62,33,21,
	41,32,25,42,16,41,23,33,13,58,
	42,57,57,52,38,68,48,67,48,27,
	69,46,10,33,63,69,22,35,15,6,
	17,10,64,15,10,39,32,55,28,37,
	40
};
int rnd(int nLow,int nUpper)
{
	
	return nLow+(nUpper-nLow)*rand()/(RAND_MAX+1);

}

double rnd(double dbLow,double dbUpper)
{
	double dbTemp=rand()/((double)RAND_MAX+1.0);
	return dbLow+dbTemp*(dbUpper-dbLow);
}

//���ظ�������������ȡ����ĸ�����
double ROUND(double dbA)
{
	return (double)((int)(dbA+0.5));
}

void ant_Init()
{
	for(int i=0;i<N_CITY_COUNT;i++)
	{
	  m_nAllowedCity[i]=1;//����ȫ������Ϊû��ȥ��
	  m_nPath[i]=0;//�����ߵ�·��ȫ������Ϊ0
	}
	m_dbPathLength=0.0;//�����߹���·����������Ϊ0
	m_nCurCityNo=rnd(0,N_CITY_COUNT);	//���ѡ��һ����������
	m_nPath[0]=m_nCurCityNo;	//���ó�������
	m_nAllowedCity[m_nCurCityNo]=0;//��ʶ��������Ϊ�Ѿ�ȥ����
	m_nMovedCityCount=1;//�Ѿ�ȥ���ĳ�����������Ϊ1
	m_blGreedSearch=false;//��ʹ��̰��ԭ��ѡ����һ����
}

int GreedChooseNextCity()
{
  int nSelectedCity=-1;//���ؽ��������ʱ��������Ϊ-1
  double dbLen=DB_MAX;
  for (int i=0;i<N_CITY_COUNT;i++)
  {
    if(m_nAllowedCity[i]==1)//ѡ��ûȥ���ĳ���
	{
	   if(g_Distance[m_nCurCItyNo][i]<dbLen)
	   {
		   dbLen=g_Distance[m_nCurCityNo][i];
		   nSelectedCity=i;
	   }
	
	}
  
  }
  return nSelectedCity;
}
int ChooseNextCity()
{
	intnSelectedCity=-1;//���ؽ��������ʱ��������Ϊ-1
	double dbTotal=0.0;
	double prob[N_CITY_COUNT];//������б�ѡ�еĸ���
	for(int i=0;i<N_CITY_COUNT;i++)
	{
		if(m_nAllowedCity[i] == 1)
		{
		prob[i]=g_Prob[m_nCurCityNo][i];
		dbTotal=dbTotal+prob[i];//�ۼ���Ϣ�أ��õ��ܺ�
		}
		else
			prob[i]=0.0;

	}

	double dbTemp=0.0;
	if(dbTotal>0.0)//�ܵ���Ϣ��ֵ����0
	{
	    dbTemp=rnd(0.0,dbTotal);//ȡһ�������
	    for(int i=0;i<N_CITY_COUNT;i++)
		{
		   if(m_nAllowedCity[i]==1)//����ûȥ��
		   {
			   dbTemp=dbTemp-prob[i];
			   if(dbTemp<0.0)
			   {
			     nSelectCity=i;
				 break;
			   }
		   }
		}
	
	}


	if(nSelectedCity==-1)
	{
		 for(int i=0;i<N_CITY_COUNT;i++)
		 {
			   if(m_nAllowedCity[i]==1)
			   {
				 nSelectedCity=i;
				 break;
		       } 
		 }
	}

	return nSelectedCity;
	
}


void ant_Move()
{
	int nCityNo=0;
	if(m_blGreedSearch ==true)
		nCityNo=GreedChooseNextCity();
	else
		nCityNo=ChooseNextCity();

	m_nPath[m_nMovedCityCount]=nCityNo;//�����ߵ�·��
	m_nAllowedCity[nCityNo]=0;//ûȥ���ĳ���
	m_nCurCityNo=nCItyNo;//��ǰ���ڳ��еı��
	m_nMovedCityCount++;//�Ѿ�ȥ���ĳ�������
}

void ant_Search()
{
	ant_Init();

	while(m_nMovedCityCount<N_CITY_COUNT)
	{
	  ant_Move();
	}

	CalPathLength();


}

void CalPathLength() //���������߹���·������
{
  m_dbPathLength=0.0;
  int m=0;
  int n=0;
  for(int i=1;i<N_CITY_COUNT;i++)
  {
     m=m_nPath[i];
	 n=m_nPath[i-1];
	 m_dbPathLength=m_dbPathLength+g_Distance[m][n];  
  }
  //���ϴ������з��س������еľ���
  n=m_nPath[0];
  m_dbPathLength=m_dbPathLength + g_Distance[m][n];

}


void tsp_InitData()
{
	//������������֮��ľ���
	double dbTemp=0.0;
	for(int i=0;i<N_CITY_COUNT;j++)
	{
	     for(int j=0;j<N_CITY_COUNT;j++)
		 {
		    dbTemp=(x_Ary[i]-x_Ary[j])*(x_Ary[i]-x_Ary[j])+(y_Ary[i]-y_Ary[j])*(y_Ary[i]-y_Ary[j]);
			dbTemp=pow(dbTemp,0.5);
			g_Distance[i][j]ROUND(dbTemp);
			g_DistanceBeat[i][j]=pow(1.0/g_Distance[i][j],BETA);
		 }
	}
	//��̰���㷨�����ʼ�Ľ�
	m_cBestAnt
  


}












