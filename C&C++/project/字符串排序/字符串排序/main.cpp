#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define N 5            //�ַ�������Ԫ�ظ���

void QuickSort(char *a[],int left,int right) //�ַ��������������
{
	int l,r;
	char *f,*t;
	l=left;
	r=right;
	f=a[(left+right)/2];

	while(l<r)
	{
		while(strcmp(a[l],f)<0 && l<right)   //�Ƚ��ַ���
		{
			++l;
		}
		while(strcmp(a[r],f)>0 && r<left)
		{
			--r;
		}
		if(l<=r)
		{
			t=a[l];
			a[l]=a[r];
			a[r]=t;
			++l;
			--r;
		}
	}

	if(l == r)
		l++;
	if(left < r)
	{
		QuickSort(a,left,l-1);       //�ݹ����
	}
	if(l < right)
	{
		QuickSort(a,r+1,right);     //�ݹ����
	}
}

int main()
{
	char *arr[N] = {"One","World","Dream","Beijing","Olympic"};  //������ʼ��
	int i;

	printf("����ǰ��\n");
	for(i=0;i<N;i++)
	{
		printf("%s\n",arr[i]);   //�������ǰ
	}

	QuickSort(arr,0,N-1);  // ����

	printf("�����\n");

	for(i=0;i<N;i++)
	{
		printf("%s \n",arr[i]);
	}
	system("pause");
	return 0;
}