#ifndef BrowseDir_H_H
#define BrowseDir_H_H
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include"Parameter.h"
using namespace std;
class CBrowseDir
{
      protected:
                //��ų�ʼĿ¼�ľ���·�����ԡ�\����β
                char m_szInitDir[_MAX_PATH];
                int m_nFileCount;  //�����ļ�����
                int m_nSubdirCount;  //������Ŀ¼����
      public:
             int GetSignal();
             bool Del_StopWord(const char *Word, int Num);
             int PreDeal(const char *filename, Item M[],int Num, char *Outfilename = NULL);
             void ExtractFeature(const char *filename, const char *output);  //�ú������� ָ��洢��������ļ�ָ��
             int CalculateGain(const char *str, Feature feature[], int Num, const char *Output);
             int WriteInfo(char *filename = NULL);
             int CharDeal(char ch);
             int Copy(Item &k,const Item M);
             int merge(Item x[],Item swap[], int k, int n);
             int mergesort(char *file = NULL);
             int ShellSort(Item M[],int N);
             int Seek(Item *Sour,const char *Des,int num);
             int Split(const char *path,char *outFile,Item M[],int num);
             int ReadStopList(const char *stoptext);
             CBrowseDir();
             
             //���ó�ʼĿ¼Ϊdir���������false,��ʾĿ¼������
             bool SetInitDir(const char *dir);
             
             //��ʼ������ʼĿ¼������Ŀ¼����filespecָ�����͵��ļ� 
             //filespec����ʹ��ͨ���*��,���ܰ���·��
             //�������false,��ʾ�������̱��û���ֹ
             
             bool BeginBrowse(const char *filespec);
      
      protected:
                int ShellSortInFreq(Item M[],int N);
                int MergesortInString(Feature feature[], int Num);
                int MergeInString(Feature x[],Feature swap[],int k,int n);
                int CopyFeature(Feature &K,const Feature X);
                int ShellSort(Feature M[],int N);
                int Unique(Item X[],int Num);
                int Mergesort(Feature feature[],int Num);
                int MergeInGain(Feature X[],Feature swap[],int k, int n);
                //����Ŀ¼dir����filespecָ�����ļ�
                //������Ŀ¼�����õ����ķ���
                //�������false����ʾ��ֹ�����ļ�
                bool BrowseDir(const char *dir,const char *filespec);
                
                //����BrowseDirû�ҵ�һ���ļ����͵���ProcessFile
                //�����ļ�����Ϊ�������ݹ�ȥ
                //�������false,��ʾ��ֹ�����ļ�
                //�û����Ը��Ǹú����������Լ��Ĵ������ 
                
                virtual bool ProcessFile(const char *filename);
                //����BrowseDirÿ����һ��Ŀ¼���͵���ProcessDir
                //�������ڴ����Ŀ¼������һ��Ŀ¼����Ϊ�������ݹ�ȥ
                // ������ڴ�����ǳ�ʼĿ¼����parentdir=NULL
                //�û����Ը���д�ú����������Լ��Ĵ������
                //�����û�����������ͳ����Ŀ¼�ĸ���
                
                virtual void ProcessDir(const char *currentdir,const char *parentdir);
                
       public:
              StopWord *stopwordArray;
              char FName[_MAX_PATH];      //�洢ͳ�ƺ���ļ����·��
              int WordofUnique;
              int WordNumber;
              char tempFName[25];       //��ʱ�洢�ļ���
              bool InfoLessWord(const char *);    //�����˵���Ϣ����С�ĵ���
              int m_switch;
              int m_StopWordNum;
              char RestoreFileName[200];   //�洢�ʿ�����
              char Restore[20];    //����ļ��洢Ŀ¼
              //�����ļ�����
              
       public��
              int GetFileCount()
              {
                  return m_nFileCount;
              }
              
              //������Ŀ¼����
              
              int GetSubdirCount()
              {
                 //��Ϊ�����ʼĿ¼ʱ��Ҳ����ú���ProcessDir,
                 //���Լ�1�������������Ŀ¼����
                 return m_nSubdirCount - 1;    
              } 
              
              ~CBrowseDir()
              {
                           delete stopwordArray;
              }
       private:
               WordReservoir WordReservoirInfo[2];
         
                
              
                 
                
      
      
      };
      
      //���Ŀ¼�Ƿ����
      
      bool DirExist(const char *pszDirName);
      
      //����Ŀ¼��������Ŀ¼�����Դ����༶��Ŀ¼
      
      bool CreateDir(const char *pszDirName);
      
     #endif 
