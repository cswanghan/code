#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10  //�����С

void HeapSort(int a[],int n)   //������
{
	int i,j,h,k;
	int t;

	for(i=n/2-1;i>=0;i--)       //��a[0,n-1]���ɴ����
	{
		while((2*i+1) < n)          //��i�������������
		{
			j = 2*i + 1;
			if((j+1)<n)
			{
				if(a[j]<a[j+1]) //������С��������������Ҫ�Ƚ�������
					j++;        //�������1,ָ��������
			}
			if(a[i]<a[j])     //�Ƚ�i��jΪ��ŵ�����
			{
				t=a[i];       //��������
				a[i]=a[j];
				a[j]=t;
				i=j;      //�ѱ��ƻ�����Ҫ���µ���
			}
			else             //�Ƚ������ӽڵ�������δ�ƻ���������Ҫ����
			{
				break;
			}
		}
	}
	//������ɵĶ�
	printf("ԭ���ݹ��ɵĶѣ�");
	for(h=0;h<n;h++)
	{
		printf("%d ",a[h]);        //���
	}
	printf("\n");

	for(i=n-1;i>0;i--)
	{
		t=a[0];           //���i����¼����
		a[0]=a[i];
		a[i]=t;
		k=0;
		while((2*k+1)<i)  //��i�������������
		{
			j=2*k+1;
			if((j+1)<i)
			{
				if(a[j]<a[j+1])       //������С��������������Ҫ�Ƚ�������
				{
					j++;         //�������1��ָ��������
				}
			}
			if(a[k]<a[j])  //�Ƚ�i��jΪ��ŵ�����
			{
				t=a[k];       //��������
				a[k]=a[j];
				a[j]=t;
				k=j;              //�ѱ��ƻ�����Ҫ���µ���
			}
			else            //�Ƚ������ӽڵ������δ�ƻ���������Ҫ����
			{
			   break;
			}
		}

		printf("��%d����������",n-i);   //���ÿ������Ľ��
		for(h=0;h<n;h++)
		{
			printf("%d ",a[h]);    //���
		}
		printf("\n");
	}
}


void main()            //������
{
	int i;
	int shuzu[SIZE];          //��������

	srand(time(NULL));
	for(i=0;i<SIZE;i++)      //��ʼ������
	{
		shuzu[i]=rand()/1000+100;
	}

	printf("����ǰ��\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",shuzu[i]);
	}

	printf("\n");

	HeapSort(shuzu,SIZE); //����

	printf("�����\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",shuzu[i]);  //���
	}
	printf("\n");
}