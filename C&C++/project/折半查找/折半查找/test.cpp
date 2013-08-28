#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 15

void QuickSort(int *arr,int left,int right)
{
	int f,t;
	int rtemp,ltemp;

	ltemp = left;
	rtemp = right;
	f = arr[(left+right)/2];
	while(ltemp < rtemp)
	{
		while(arr[ltemp] < f)
		{
			++ltemp;
		}
		while(arr[rtemp] > f)
		{
			--rtemp;
		}
		if(ltemp <= rtemp)
		{
			t = arr[ltemp];
			arr[ltemp] = arr[rtemp];
			arr[rtemp] = t;
			--rtemp;
			++ltemp;
		}
	}

	if(ltemp == rtemp)
	{
		ltemp++;

	}

	if(left < rtemp)
	{
		QuickSort(arr,left,ltemp-1);
	}
	if(ltemp <right)
	{
		QuickSort(arr,rtemp+1,right);
	}
}

int SearchFun(int a[],int n,int x)
{
	int mid,low,high;
	low =0;
	high = n-1;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(a[mid] == x)
			return mid;
		else if(a[mid] > x)
			high = mid -1;
		else
			low = mid + 1;
	}
	return -1;
}

void main()
{
	int shuzu[N],x,n,i;

	srand(time(NULL));

	for(i=0;i<N;i++)
	{
		shuzu[i] = rand()/1000 + 100;
	}
	printf("�۰�����㷨��ʾ��\n");
	printf("����ǰ�������У�\n");

	for(i=0;i<N;i++)
	{
		printf("%d ",shuzu[i]);
	}
	printf("\n\n");

	QuickSort(shuzu,0,N-1);
	printf("������������У�\n");
	for(i=0;i<N;i++)
	{
		printf("%d ",shuzu[i]);
	}
	printf("\n\n");
	printf("����Ҫ���ҵ�����");
	scanf("%d ",&x);

	n = SearchFun(shuzu,N,x);

	if(n < 0)
	{
		printf("û�ҵ����ݣ�%d ",x);

	}
	else
	{
		printf("����%d λ������ĵ�%d��Ԫ�ش�.\n",x,n+1);
	}
}