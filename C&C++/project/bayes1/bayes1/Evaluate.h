#ifndef Evaluate_H_H
#define Evaluate_H_H
#include<iostream.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<conio.h>
#include"Parameter.h"
#include"BrowseDir.h"


static int m_FeedSetFileNum[2];

class CEvaluate
{

public:
       int GetFileCount();
       int WriteInfo(char *filename);
       int CopyFeature(Feature &K,const Feature X);
       int GetAccuracy();
       bool BrowseDir(const char *dir,const char *filespec);
       bool ProcessFile(const char *filename);
       bool BeginBrowse(const char *filespec);
       bool SetInitDir(const char *dir);
       CEvaluate();
       ~CEvaluate()
       {
                   delete stopwordArray;
       }
       int Classify(const char *str,int Num);
       int ShellSortKeyWords(FileNode &filenode,int N);
       int SelectFeature(Feature feature[],int Num);
       int PreDealFile(const char *filename,FileNode &filenode);
       int SeekKeyWords(FileNode Src, const char *Des, int num);
       int ShellSortAccordStr(Feature M[],int N);  //���ַ����������� 
       
       
protected:
          bool Del_StopWord(const char *Word,int Num);
          int ReadStopList(const char *stoptext);
          int Binary(const char *Src,FileNode filenode,int N);
          int MergesortInString(Feature feature[],int Num);
          int MergeInKeyString(FileNode &filenode,KeyWord swap[], int k,int n);
          int ReadInfo();
          int merge(Item x[],Item swap[],int k,int n);
          int mergesort(char *file,int Setflag);
          int Copy(Item &K,const Item M);
          int FeedBack(const char *filename,int flag);
          int ShellSort(Item M[],int N);//��������������������
          int ShellSortInFreq(Item M[],int N); //�������������г��ֵĴ�����������
          int Seek(Item *Sour,const char *Des, int num);
          
public:
       WordReseroir WordReservoirInfo[2];
       int flag;  //ָ���ʼ���־
       int m_nFileCount;
       int m_nAccuracy;  //��¼������ȷ���ʼ�����
       double m_SetFileNum[2];
       
protected:
         StopWord *stopwordArray;
         int m_StopWordNum;
         int MergeInKeyWords(FileNode &filenode, int N);
         char m_MailDir[40];  //��������ʼ�·��
         char m_szInitDir[_MAX_PATH]; 
private:      
      
      
};
#endif
