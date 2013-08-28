#include<string.h>
#include<stdio.h>
#include<malloc.h>

#define Num 41
#define KillMan 3

void Josephus(int alive)
{
	int man[Num] = {0};
	int count = 1;
	int i=0,pos =-1;

	while(count <= Num)
	{
		do{
			pos = (pos+1)%Num;
			if(man[pos] == 0)
				i++;
			if(i == KillMan)
			{
				i=0;
				break;
			}
		}while(1);
		man[pos] = count;
		printf("��%2d������ɱ��Լɪ�򻷱��Ϊ%2d",pos+1,man[pos]);
		if(count%2)
		{
			printf("->");
		}
		else
		{
			printf("->\n");
		}
		count++;
	}

	printf("\n");
	printf("��%d��Ҫ�����˳�ʼλ��Ӧ����������ţ�\n",alive);
	alive = Num - alive;
	for(i=0;i<Num;i++)
	{
		if(man[i] > alive)
		{
			printf("��ʼ��ţ�%d,Լɪ�򻷱��:%d\n",i+1,man[i]);
		}
	}
	printf("\n");
}

void main()
{
	int alive;
	printf("Լɪ��������⣡\n");
	printf("������Ҫ������˵�������");
	scanf("%d ",&alive);
	fflush(stdin);
	Josephus(alive);
}