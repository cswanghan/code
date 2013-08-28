#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define QUEUELEN 15      //��󳤶�

typedef struct
{
   char name[10];
   int age;
}DATA;

typedef struct 
{
  DATA data[QUEUELEN];                //��������
  int head;                     //��ͷ
  int tail;               //��β
}SQType;


SQType *SQTypeInit()
{
  SQType *q;
  if(q=(SQType*)malloc(sizeof(SQType)))       //�����ڴ�
  {
	  q->head = 0;                  //���ö�ͷ
	  q->tail = 0;                   //���ö�β
	  return q;
  }else
  {
     return NULL;               //���ؿ�
  }
}

int SQTypeIsEmpty(SQType *q)        //�жϿն���
{
  int temp;
  temp = q->head==q->tail;
  return (temp);
}

int SQLTypeIsFull(SQType *q)   //�ж�������
{
 int temp;
 temp=q->tail == QUEUELEN;
 return (temp);
}

void SQTypeClear(SQType *q)            //��ն���
{
	q->head = 0;            //���ö�ͷ
	q->tail = 0;          //���ö�β
}

void SQTypeFree(SQType *q)       //�ͷŶ���
{
  if(q!=NULL)
  {
	  free(q);
  }
}

int InSQType(SQType *q,DATA data)            //�����
{
	if(q->tail == QUEUELEN)
	{
		printf("��������������ʧ�ܣ�\n");
		return (0);
	}
	else {
		q->data[q->tail++] = data;            //��Ԫ�������
		return (1);
	
	}
}

DATA *OutSQType(SQType *q)         //������
{
	if(q->head == q->tail)
	{
		printf("\n �����ѿգ�����ʧ�ܣ�\n");
			exit(0);
	}else {
		return &(q->data[q->head++]);
	}
}

DATA *PeekSQType(SQType *q)            //���������
{
	if(SQTypeIsEmpty(q))
	{
		printf("\n �ն���!\n");
		return NULL;
	}else
	{
		return &(q->data[q->head]);
	}
}

int SQTypeLen(SQType *q)         //������г���
{
	int temp;
	temp=q->tail-q->head;
	return (temp);
}

void main()
{
  SQType *stack;
  DATA data;
  DATA *data1;

  stack = SQTypeInit();
  printf("����в�����\n");
	  printf("��������  �����������в�����");
	  do{
		scanf("%s%d,",data.name,&data.age);
		if(strcmp(data.name,"0")==0)
		{
			break;                            //������0,���˳�
		}else{
			InSQType(stack,data);
		}
	  
	  }while(1);

	  do{
			printf("�����в���������������г�ջ����:\n");
			getchar();
			data1 = OutSQType(stack);
			printf("�����е������ǣ�%s,%d��\n",data1->name,data1->age);
	  }while(1);
	  SQTypeFree(stack);               //�ͷ����ж�����ռ�õĿռ�
}

