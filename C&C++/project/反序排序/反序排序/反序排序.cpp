// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define SIZE 10  //�����С


void InsertionSort(int *a,int len){   //��������
	int i,j,t,h;
	for(i=1;i<len;i++){
		t = a[i];
		j = i-1;
		while(j>=0&&t>a[j])  //����
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;

		printf("��%d����������",i);   //���ÿ������Ľ��
		for(h=0;h<len;h++)
		{
			printf("%d ",a[h]);    //���
		}
		printf("\n");
	}
}

void main()
{
	int arr[SIZE],i;  //��������

	srand(time(NULL));
	for(int i=0;i<SIZE;i++)
	{
		arr[i] = rand()/1000 + 100;
	}
	printf("����ǰ��\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",arr[i]);    //���
	}

	printf("\n");

	InsertionSort(arr,SIZE);    //��������

	printf("�����\n");

	for(i=0;i<SIZE;i++)
	{
		printf("%d ",arr[i]);  //���
	}

	printf("\n");
}




