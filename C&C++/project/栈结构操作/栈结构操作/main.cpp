#include<stdlib.h>
#include<stdio.h>
#include<string.h>


#define MAXLEN 50          //��󳤶�
#define SIZE 10

typedef struct
{
  char name[10];
  int age;
}DATA;

typedef struct stack
{
  DATA data[SIZE+1];             //����Ԫ��
  int top;                     // ջ��
}StackType;

StackType *STInit()
{
	StackType *p;
	if(p=(StackType*)malloc(sizeof(StackType))){       //����ջ�ڴ�
		p->top=0;                //����ջ��Ϊ0
		return p;                //����ָ��ջ��ָ��
	}
	return NULL;
}

int STIsEmpty(StackType *s)   //�ж�ջ�Ƿ�Ϊ��
{
   int t;
   t = (s->top==0);
   return t;
}

int STIsFull(StackType *s)      //�ж�ջ�Ƿ�����
{
   int t;
   t = (s->top == MAXLEN);
   return t;
}

void STClear(StackType *s){          //���ջ
	s->top =0;

}

void  STFree(StackType *s)       //�ͷ�ջ��ռ�õĿռ�
{
  if(s)
  {
    free(s);
  }
}

int PushST(StackType *s,DATA data)     //��ջ����
{
	if((s->top+1)>MAXLEN)
	{
	  printf("ջ�����\n");
		  return 0;
	}
	s->data[++s->top]=data;      //��Ԫ����ջ
	return 1;
}

DATA PopST(StackType *s)           //��ջ����
{
	if(s->top == 0)
	{
	  printf("ջΪ�գ�\n");
		  exit(0);
	}
	return (s->data[s->top--]);
}

DATA PeekST(StackType *s)      //��ջ������
{
	if(s->top==0)
	{
	  printf("ջΪ�գ�\n");
	  exit(0);
	}
	return (s->data[s->top]);
}


void main()
{
  StackType *stack;
  DATA data,data1;
  
  stack = STInit();
  printf("��ջ����:\n");
  printf("�������� ���������ջ������");
  do
  {
	  scanf("%s%d",data.name,&data.age);
	  if(strcmp(data.name,"0")==0)
	  {
	    break;                     //������0�����˳�
	  }else
	  {
	    PushST(stack,data);
	  }

  }while(1);

  do
  {
   printf("\n��ջ����������������г�ջ������");
   getchar();
   data1 = PopST(stack);
   printf("��ս�������ǣ�%s,%d��",data1.name,data1.age);
  
  }while(1);
  STFree(stack);                        //�ͷ�ջ��ռ�õĿռ�
}