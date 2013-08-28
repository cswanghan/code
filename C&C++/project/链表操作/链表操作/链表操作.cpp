// �������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
   char key[10];                          //�ؼ���
   char name[20];
   int age;
}Data;                                   //���ݽڵ�����
typedef struct Node{                   //��������ṹ
  Data nodeData;
  struct Node *nextNode;
}CLType;

CLType *CLAddEnd(CLType *head,Data nodeData)   //׷�ӽڵ�
{
   CLType *node,*htemp;
   if(!(node=(CLType*)malloc(sizeof(CLType)))){
    printf("�����ڴ�ʧ�ܣ�\n");
	return NULL;
   }                                 //�����ڴ�ʧ��
   else{
	   node->nodeData = nodeData;          //��������
	   node->nextNode = NULL;               //���ý��ָ��Ϊ�գ���Ϊ��β
	   if(head == NULL){                    //ͷָ��
	     head = node;
		 return head;
	   }
	   htemp = head;
	   while(htemp->nextNode != NULL)           //���������ĩβ
	   {
		   htemp = htemp->nextNode;
	   }
	   htemp->nextNode = node;
	   return head;
   }
}

CLType *CLAddFirst(CLType *head,Data nodeData)
{
   CLType *node;
   if(!(node=(CLType *)malloc(sizeof(CLType))))
   {
      printf("�����ڴ�ʧ�ܣ�\n");
	  return NULL;                                 //�����ڴ�ʧ��
   }else{
	   node->nodeData = nodeData;                 //��������
	   node->nextNode = head;                    //ָ��ͷָ����ָ���
	   head = node;                      //ͷָ��ָ���������
		   return head;            
   }
}

CLType *CLFindNode(CLType *head,char *key)              // ���ҽ��
{
   CLType *htemp;              
   htemp = head;                                 //��������ָ��
   while(htemp){                            //�������Ч������в���
	   if(strcmp(htemp->nodeData.key,key) == 0){    //�����ؼ����봫��ؼ�����ͬ
	      return htemp;                           //���ظý��ָ��
	   }
	   htemp = htemp->nextNode;                 //������һ�����
   }
   return NULL;                    //���ؿ�ָ��
}

CLType *CLInsertNode(CLType *head,char *findkey,Data nodeData)  //������
{
  CLType *node,*nodetemp;
  if(!(node=(CLType *)malloc(sizeof(CLType)))){          //���䱣���������
           printf("�����ڴ�ʧ�ܣ�\n");
			   return 0;                                 //�����ڴ�ʧ��
  }
  node->nodeData = nodeData;                   //����ڵ��е�����
  nodetemp = CLFindNode(head,findkey);             
  if(nodetemp){                           //���ҵ�Ҫ����Ľڵ�
	  node->nextNode = nodetemp->nextNode;    // �²�����ָ��ؼ��ڵ����һ�ڵ�
	  nodetemp->nextNode = node;              //���ùؽڽڵ�ָ���²�����
  }
  else{
      printf("δ�ҵ���ȷ�Ĳ���λ�ã�\n");          
	  free(node);                  //�ͷ��ڴ�
  }
  return head;      //����ͷָ��

}

int CLDeleteNode(CLType *head,char *key){
  CLType *node,*htemp;            //node����ɾ���ڵ��ǰһ�ڵ�
  htemp = head;
  node = head;
  while(htemp){
	  if(strcmp(htemp->nodeData.key,key)==0)          //���ҹؼ��֣�ִ��ɾ������
	  {
		  node->nextNode = htemp->nextNode;   //ʹǰһ�ڵ�ָ��ǰ�ڵ����һ�ڵ�
		  free(htemp);            //�ͷ��ڴ�
	      return 1;
	  }
	  else{
	    node =htemp;                       //ָ��ǰ�ڵ�
		htemp = htemp->nextNode;            //ָ����һ�ڵ�
	  }
  }
  return 0;                         //δɾ��
} 


int CLLength(CLType *head)    //����������
{
	CLType *htemp;
	int Len = 0;
	htemp = head;
	while(htemp){                 //������������
	  Len++;                               //�ۼӽڵ�����
	  htemp=htemp->nextNode;           //������һ�ڵ�
	}
	return Len;                  //���ؽڵ�����
}


void CLAllNode(CLType *head){          //��������
	CLType * htemp;
	Data nodeData;
	htemp = head;
	printf("��ǰ������%d ���ڵ㡣���������������£�\n",CLLength(head));
	while(htemp){                         //ѭ����������ÿ���ڵ�
		nodeData = htemp->nodeData;                 //��ȡ�ڵ�����
		printf("�ڵ㣨%s,%s,%d��\n",nodeData.key,nodeData.name,nodeData.age);
		htemp=htemp->nextNode;                    //������һ���ڵ�
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	CLType *node, *head = NULL;
	Data nodeData;
	char key[10],findkey[10];

	printf("������ԡ������������е����ݣ���ʽΪ���ؼ���  ����  ����\n");
	do{
	      fflush(stdin);           //��ջ�����
		  scanf("%s",nodeData.key);
		  if(strcmp(nodeData.key,"0")==0){
		       break;      //������0�����˳�
		  }
		  else{
			  scanf("%s%d",nodeData.name,&nodeData.age);
			  head = CLAddEnd(head,nodeData);           //������β����ӽڵ�
		  
		  }
	
	}while(1);
	CLAllNode(head);           //��ʾ���нڵ�

	printf("\n ��ʾ����ڵ㣬�������λ�õĹؼ��֣�");
	scanf("%s",&findkey);
	printf("�������������ݣ��ؼ���  ����  ���䣩��");
	scanf("%s%s%d",nodeData.key,nodeData.name,&nodeData.age);//�������������
	head = CLInsertNode(head,findkey,nodeData);         //���ò��뺯��
	CLAllNode(head);             //��ʾ���нڵ�

	printf("\n ��ʾɾ���ڵ㣬����Ҫɾ���Ĺؼ��֣�");
	fflush(stdin);//    ������뻺����
	scanf("%s",key);   //����ɾ�����ؼ���
	CLDeleteNode(head,key);  //����ɾ���ڵ㺯��
	CLAllNode(head);      //��ʾ���н��

	printf("\n ��ʾ�������в��ң�������ҹؼ��֣�");
	fflush(stdin);  //������뻺����
	scanf("%s",key);     //������ҹؼ���
	node = CLFindNode(head,key);    //���ò��Һ��������ؽڵ�ָ��
	if(node){
		nodeData = node->nodeData;              //��ȡ�ڵ������
		printf("�ؼ���%s��Ӧ�Ľڵ�Ϊ��%s,%s,%d��\n",key,nodeData.key,nodeData.name,nodeData.age);
	
	 }else{             //�����ָ����Ч
		 printf("��������δ�ҵ��ؼ���Ϊ%s�Ľڵ㣡\n",key);
	}




	return 0;
}

