#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 15

int SearchFun(int a[],int n,int x)
{
	int i,f = -1;
	for(i=0;i<n;i++)
	{
		if(x == a[i])
		{
			f = i;
			break;
		}
	}
	return f;
}

void main()
{
	int x,n,i;
	int shuzu[N];

	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		shuzu[i] = rand()/1000 +100;

	}


	printf("˳������㷨��ʾ��\n");
		printf("�����б�\n");
		for(i=0;i<N;i++)
		{
			printf("%d  ",shuzu[i]);
		}
		printf("\n\n");
		printf("����Ҫ���ҵ�����");
		scanf("%d",&x);

		n=SearchFun(shuzu,N,x);

		if(n<0)
		{
			printf("û�ҵ����ݣ�%d\n",x);
		}else
		{
			printf("���ݣ�%d λ������ĵ�%d ��Ԫ�ش�.\n",x,n+1);
		}
}