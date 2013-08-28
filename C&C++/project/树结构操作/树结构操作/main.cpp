#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

#define MANLEN 20  //��󳤶�
typedef char DATA;        //����Ԫ������
typedef struct CBT    //����������ڵ�����
{
	DATA data;               //Ԫ������
	struct CBT *left;         //���������ָ��
	struct CBT *right;        //���������ָ��

}CBTType;


CBTType *InitTree()
{
  CBTType *node;

  if(node=(CBTType*)malloc(sizeof(CBTType)))
  {
	printf("������һ�����ڵ����ݣ�\n");
	scanf("%s",&node->data);
	node->left = NULL;
	node->right = NULL;
	if(node != NULL)
	{
		return node;
	}else
	{
		return NULL;
	}

  }
  return NULL;

}

CBTType *TreeFindNode(CBTType *treeNode,DATA data)         //���ҽ��
{
	CBTType *ptr;
	if(treeNode == NULL)
	{
		return NULL;
	}
	else
	{	
		if(treeNode->data == data)
		{	
			return treeNode;
		}
		else
		{
			if(ptr = TreeFindNode(treeNode->left,data))            //�ֱ������������ݹ����
			{
				return ptr;
			}else if(ptr = TreeFindNode(treeNode->right,data))
			{
				return ptr;
			}
			else
			{
				return NULL;
			}
		}
	}

}


void AddTreeNode(CBTType *treeNode)
{
   CBTType *pnode,*parent;
   DATA data;
   char menusel;

   if(pnode=(CBTType *)malloc(sizeof(CBTType)))     //�����ڴ�
   {
	printf("����������ڵ����ݣ�\n");
	fflush(stdin);   //������뻺����
	scanf("%s",&pnode->data);
	pnode->left = NULL;
	pnode->right = NULL;

	printf("����ýڵ�ĸ��ڵ����ݣ�");
	fflush(stdin);
	scanf("%s",&data);
	parent = TreeFindNode(treeNode,data);    //����ָ�����ݵĽڵ�
	if(!parent)
	{
		printf("δ�ҵ��ø��ڵ㣡\n");
		free(pnode);                   //�ͷŴ����Ľڵ��ڴ�
		return;
	}
	printf("1.��Ӹýڵ㵽������\n2.��Ӹýڵ㵽������\n");
		do{
		
			menusel = getch();          //����ѡ����
			menusel-='0';
			if(menusel == 1 || menusel == 2)
			{
				if(parent == NULL)
				{
					printf("�����ڸ��ڵ㣬�������ø��ڵ㣡\n");
				}
				else
				{
					switch(menusel)
					{
					case 1:                //��ӵ���ڵ�
						if(parent->left)          //��ڵ㲻Ϊ��
						{
							printf("�������ڵ㲻Ϊ�գ�\n");
						}
						else
						{
							parent->left = pnode;
						}
						break;
					case 2:                      //��ӵ��ҽڵ�
						if(parent->right)    //��������Ϊ��
						{
							printf("�������ڵ㲻Ϊ�գ�\n");
						}
						else
						{
							parent->right = pnode;
						}
						break;
					default:
						printf("��Ч�μӣ�\n");
					}
				}
			}
		}while(menusel!=1 && menusel !=2);
   }
}





CBTType *TreeLeftNode(CBTType *treeNode)      //��ȡ������
{
	if(treeNode)
	{
		return treeNode->left;     //����ֵ
	}else
	{
		return NULL;
	}
}

CBTType *TreeRightNode(CBTType *treeNode)      //��ȡ������
{
	if(treeNode)
	{
		return treeNode->right;         //����ֵ
	}
	else
	{
		return NULL;
	}
}


int TreeIsEmpty(CBTType *treeNode)         //�жϿ���
{
	if(treeNode)
	{
		return 0;
	}else
	{
		return 1;
	}
}

int TreeDepth(CBTType *treeNode)        //������������
{
	int depleft,depright;

	if(treeNode == NULL)
	{
		return 0;            //���ڿ��������Ϊ0
	}
	else
	{
		depleft = TreeDepth(treeNode->left);  //��������ȣ��ݹ���ã�
		depright = TreeDepth(treeNode->right);  //��������ȣ��ݹ���ã�
		if(depleft>depright)
		{
			return depleft +1;
		}
		else{
			return depright + 1;
		}
	}
}


void ClearTree(CBTType * treeNode)
{
	if(treeNode)
	{
		ClearTree(treeNode->left);     //���������
		ClearTree(treeNode->right);      //���������
		free(treeNode);   //�ͷŵ�ǰ�ڵ���ռ�ڴ�
		treeNode = NULL;
	}
}


void TreeNodeData(CBTType *p)          //��ʾ�������
{
	printf("%c",p->data);            //����������
}


void LevelTree(CBTType *treeNode,void(*TreeNodeData)(CBTType *p))   //�������
{
	CBTType *p;
	CBTType *q[MANLEN];  //����һ��˳��ջ
	int head = 0,tail = 0;

	if(treeNode)                    //�������ָ�벻Ϊ��
	{
		tail = (tail+1)%MANLEN;            //����ѭ�����ж�β���
		q[tail] = treeNode;                 //����������ָ�����
	}
	while(head!=tail)                    //���в�Ϊ�գ�����ѭ��
	{ 
		head = (head +1)%MANLEN;           //����ѭ�����еĶ������
		p=q[head];                  //��ȡ����Ԫ��
		TreeNodeData(p);      //�������Ԫ��
		if(p->left!=NULL)      //����ڵ����������
		{
			tail = (tail+1)%MANLEN; //����ѭ�����еĶ�β���
			q[tail] = p->left;         //��������ָ�����
		}

		if(p->right != NULL)          //���������������
		{
			tail = (tail + 1)%MANLEN;    //����ѭ�����еĶ�β���
			q[tail] = p->right;        //��������ָ�����
		}
	}
}


void DLRTree(CBTType *treeNode,void (*TreeNodeData)(CBTType *p))  //�������
{
	if(treeNode)
	{
		TreeNodeData(treeNode);           //��ʾ��������
		DLRTree(treeNode->left,TreeNodeData);
		DLRTree(treeNode->right,TreeNodeData);
	}
}

void LDRTree(CBTType *treeNode,void(*TreeNodeData)(CBTType *p))   //�������
{
	if(treeNode)
	{
		LDRTree(treeNode->left,TreeNodeData);
		TreeNodeData(treeNode);
		LDRTree(treeNode->right,TreeNodeData);
	}
}

void LRDTree(CBTType *treeNode,void(*TreeNodeData)(CBTType *p))  //�������
{
	if(treeNode)
	{
		LRDTree(treeNode->left,TreeNodeData);
		LRDTree(treeNode->right,TreeNodeData);
		TreeNodeData(treeNode);
	}
}



void main()
{
	CBTType *root=NULL;
	char  menusel;
	void (*TreeNodeData1)(CBTType *p);
	TreeNodeData1=TreeNodeData;

	root = InitTree();
	do{
		printf("��ѡ��˵���Ӷ������Ľڵ�\n");
		printf("0.�˳�\t");
		printf("1.��Ӷ������Ľڵ�\n");
		menusel = getch();
		switch(menusel)
		{
		case '1':
			AddTreeNode(root);
			break;
		case '0':
			break;
		default:
			;
		}
	}while(menusel != '0');

	do{
		printf("��ѡ��˵�����������������0��ʾ�˳���\n");
		printf("1.�������DLR\t");
		printf("2.�������LDR\n");
		printf("3.�������LRD\t");
		printf("4.�������\n");


		menusel = getch();
		switch(menusel)
		{
		case '0':
			break;
		case '1':
			printf("\n �������DLR�Ľ����");
			DLRTree(root,TreeNodeData1);
			printf("\n");
			break;
		case '2':
			printf("\n�������LDR�Ľ����");
			LDRTree(root,TreeNodeData1);
			printf("\n");
			break;
		case '3':
			printf("\n �������LRD�Ľ����");
			LRDTree(root,TreeNodeData1);
			printf("\n");
			break;
		case '4':
			printf("\n ��������Ľ����");
			LevelTree(root,TreeNodeData1);
			printf("\n");
			break;
		default:
			;
		}
	
	}while(menusel != '0');

	printf("\n ���������Ϊ��%d \n",TreeDepth(root));

	ClearTree(root);
	root = NULL;


}

