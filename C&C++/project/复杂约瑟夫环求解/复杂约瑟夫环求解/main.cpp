#include<string.h>
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int number;
	int psw;
	struct node *next;
}LNode,*LinkList;

void insertList(LinkList *list,LinkList q,int number,int psw)
{
	LinkList p;

	p=(LinkList)malloc(sizeof(LNode));
	p->number = number;
	p->psw = psw;

	if(!*list)
	{
		*list = p;
		p->next = NULL;
	}
	else
	{
		p->next = q->next;
		q->next = p;
	}
}

void CircleFun(LinkList *list,int m)
{
	LinkList p,q;
	int i;
	p=q=*list;
	while(q->next != p)
	{
		q = q->next;
	}

	printf("��Ϸ�߰������µ�˳����С�\n");
	while(p->next != p)
	{
		for(i=0;i<m;i++)
		{
			q =p;
			p = p->next;
		}
		q->next = p->next;
		printf("��%d���˳��У������еĳ�������Ϊ%d.\n",p->number,p->psw);
		m = p->psw;
		free(p);
		p=q->next;
	}
	printf("���һ������%d,�����еĳ�������Ϊ%d��",p->number,p->psw);
}


void main()
{
	LinkList list1 = NULL,q=NULL,list;
	int num,baoshu;

	int i,e;
	printf("Լɪ��������⣡\n");
	printf("������Լɪ���е�������\n");
	scanf("%d",&num);

	printf("����˳������ÿ�������еĳ������֣�\n");

	for(i=0;i<num;i++)
	{
		scanf("%d",&e);
		insertList(&list1,q,i+1,e);
		if(i == 0)
		{
			q=list1;
		
		}else
		{
			q=q->next;
		}
	}
	q->next = list1;
	list = list1;

	printf("�������һ�γ��е����֣�\n");
	scanf("%d",&baoshu);
	CircleFun(&list,baoshu);
	printf("\n");
}