#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10


void MergeOne(int a[],int b[],int n,int len)     //���һ��ϲ��ĺ���
{
	int i,j,k,s,e;

	s=0;

	while((s+len) < n)
	{
		e = s+2*len-1;
		if(e>=n)
		{
			e=n-1;
		}

	   //��������κϲ�
		k=s;
		i=s;
		j=s+len;

		while(i<(s+len)&&(j<=e))
		{
			if(a[i]<=a[j])
			{
				b[k++]=a[i++];
			}
			else
			{
				b[k++]=a[j++];
			}
		}
		while(i<(s+len))
		{
			b[k++]=a[i++];
		}
		while(j<=e)
		{
			b[k++]=a[j++];
		}
		s=e+1;
	}

	if(s<n)
	{
		for(;s<n;s++)
		{
			b[s] = a[s];
		}
	}
}

void MergeSort(int a[],int n)    //�ϲ�����
{
	int *p;
	int h,count,len,f;

	count = 0;   //������
    len = 1; //�������еĳ���
	f =0;     //����f����־
	if(!(p=(int*)malloc(sizeof(int)*n)))  //�����ڴ�ռ�
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(0);
	}
	while(len<n)
	{
		if(f == 1)
		{
			MergeOne(p,a,n,len);
		}
		else
		{
			MergeOne(a,p,n,len);
		}
		len = len*2;    //�����������г���
		f=1-f;     //ʹfֵ��0��1֮���л�

		count++;
		printf("��%d����������",count);
		for(h=0;h<SIZE;h++)
		{
			printf("%d ",a[h]);
		}
		printf("\n");
	}
	if(f)
	{
		for(h=0;h<n;h++)
		{
			a[h] =p[h];
		}
	}
	free(p);

}

void main()
{
	int i;
	int shuzu[SIZE];

	srand(time(NULL));
	for(i=0;i<SIZE;i++)
	{
		shuzu[i] = rand()/1000 + 100;
	}

	printf("����ǰ��\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",shuzu[i]);
	}
	printf("\n\n");

	MergeSort(shuzu,SIZE);

	printf("�����\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",shuzu[i]);
	}

	printf("\n\n");
}