#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

void BubbleSort(int *a, int len)
{
	int i,j,k,temp;

	for(i = 0;i<len-1;i++)
	{
		for(j=len-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
		printf("��%d��������",i);
		for(k=0;k<len;k++)
		{
			printf("%d ",a[k]);
		}
		printf("\n");
	}

}


void main()
{
	int shuzu[SIZE],i;

	srand(time(NULL));

	for(i=0;i<SIZE;i++)
	{
		shuzu[i]=rand()/1000 + 100;
	}

	printf("����ǰ������Ϊ��\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d  ",shuzu[i]);
	}

	printf("\n");

	BubbleSort(shuzu,SIZE);

	printf("���������飺\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d  ",shuzu[i]);
	}

	printf("\n");
}