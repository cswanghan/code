#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
	char key[10];
	char name[20];
	int age;
}Data;

typedef struct Node
{
	Data nodeData;
	struct Node *nextNode;
}CLType;

CLType *CLAddEnd(CLType *head,Data nodeData)
{
	CLType *node,*htemp;
	if(!(node = (CLType*) malloc(sizeof(CLType))))
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		return NULL;
	}
	else
	{
		node->nodeData = nodeData;
		node->nextNode = NULL;
		if(head == NULL)
		{
			head = node;
			return head;
		}
		htemp = head;
		while(htemp->nextNode!=NULL)
		{
			htemp = htemp->nextNode;
		}
		htemp->nextNode = node;
		return head;
	}
}

CLType *CLFindNode(CLType *head,char *key)
{
	CLType *htemp;
	htemp = head;
	while(htemp)
	{
		if(strcmp(htemp->nodeData.key,key) == 0)
		{
			return htemp;
		}
		htemp = htemp->nextNode;
	}
	return NULL;
}

int CLLength(CLType *head)
{
	CLType *htemp;
	int Len = 0;
	htemp = head;
	while(htemp)
	{
		Len++;
		htemp = htemp->nextNode;
	}
	return Len;
}


void CLAllNode(CLType *head)
{
	CLType *htemp;
	Data nodeData;
	htemp = head;
	printf("��ǰ������ %d ����㡣���������������£�\n",CLLength(head));
	while(htemp)
	{
		nodeData = htemp->nodeData;
		printf("��㣨%s,%s,%d��\n",nodeData.key,nodeData.name,nodeData.age);
		htemp = htemp->nextNode;
	}
}

void main()
{
	CLType *node,*head = NULL;
	Data nodeData;
	char key[10];
	printf("������ԡ������������е����ݣ���ʽΪ���ؼ��� ���� ���� \n");
	do{
	 fflush(stdin);
	 scanf("%s",nodeData.key);
	 if(strcmp(nodeData.key,"0") == 0)
	 {
		 break;
	 }
	 else
	 {
		 scanf("%s%d",nodeData.name,&nodeData.age);
		 head = CLAddEnd(head,nodeData);
	 }
	
	}while(1);
	CLAllNode(head);

	printf("\n��ʾ�������в��ң�������ҹؼ��֣�");
	fflush(stdin);
	scanf("%s",key);
	node = CLFindNode(head,key);
	if(node)
	{
		nodeData = node->nodeData;
		printf("�ؼ���%s��Ӧ�Ľ��Ϊ��%s,%s,%d��\n",key,nodeData.key,nodeData.name,nodeData.age);
	}
	else
	{
		printf("��������δ�ҵ��ؼ���%s�Ľ��!\n",key);
	}
}
