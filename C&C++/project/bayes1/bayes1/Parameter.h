#ifndef Paramter_H_H
#define Paramter_H_H
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<conio.h>

//����Ľṹ����BrowseDir����

typedef struct Item       // �洢ÿ�����ʵ���Ϣ
{
        char str[40];
        int freq;        //��ĳƪ�����г��ֵĴ���
        float density;
        int Sequence;   //���±��
        int FileCnt;     //�ڶ���ƪ�����г��ֵĴ���
        int flag;
        int SetInfo;    //��������Ϣ
        double gain;    //���ʵ����� 
} Item;

typedef struct WordGain    //�������ʼ��������ʼ��Ĵʿ�ϲ������ڴ洢������Ϣ
{
        char str[40];
        
        int flag0;           //flag0��ʾ�õ����������ʼ��г��� 
        int freq0;
        int density0;       
        int FileCnt0;   //�ڶ��ٷ������ʼ��г���
        
        int flag1;          //flag1��ʾ�õ��ʵ������ʼ��г��� 
        int freq1;
        int density1;
        int FileCnt1;    //�ڶ��ٷ������ʼ��г���
        
        double qain;   //���ʵ����� 
         
        
}WordGain;

typedef struct WordReservoir   //�ʿ���Ϣ��������
{
        char ClassFileName[100];  //�洢�ʿ����ȫ·��������
        int ClassFlag;  //�ʿ����� 1 ��ʾ�������ʼ���ȡ�Ĵʿ�
                                   // 0 ��ʾ�����ʼ���ȡ�Ĵʿ� 
        int FileSum;     //�����ļ���������
        int WordSum;     //�����ĵ��ʵ����� 
}Wordreservoir;

typedef struct Feature     //�洢��������Ϣ���ݽṹ
{
         char str[40];
         int NormalMail;
         int UnNormalMail;
         double NormalMail_Prior;
         double UnNormalMail_Proir;
         double gain;        
}Feature;

static int ClassCnt = 0;

//����Ľṹ����Evaluate����

typedef struct KeyWord   //�洢�ؼ���
{
        char str[40];
        
}KeyWord,StopWord;

typedef struct FileName   //�洢������Ϣ�����ļ������ؼ����б������ķ�����Ϣ
{
        char filename[40];   //�ļ���
        KeyWord keys[1200];   //�ؼ����б�
        int flag;        //���ķ�����Ϣ 
}FileNode; 
 
 static int TsetKeyWordNumber = 200;  //����ʱ��������Ŀ��ʼ��
 static int EObjectCnt = 0;     //����Evaluate��Ĺ��캯�����棬�������
 
 static char Path[30] = "E:\\ReadDir\\";
 
 #define KeyNum 30    //ÿ���ʼ�����ȡKeyNum�����ʳ����������������㣬�����ʼ��жϵ�׼ȷ��Ӱ��Ƚϴ�
 
 #endif 
 
         
