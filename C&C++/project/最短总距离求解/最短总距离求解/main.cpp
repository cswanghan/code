#include<stdio.h>

#define MaxNum 20
#define MaxValue 65535

#define USED 0
#define NoL -1

typedef struct
{
	char Vertex[MaxNum];
	int GType;
	int VertexNum;
	int EdgeNum;
	int EdgeWeight[MaxNum][MaxNum];
	int isTrav[MaxNum];
}GraphMatrix;

void CreateGraph(GraphMatrix *GM)
{
	int i,j,k;
	int weight;
	char EstartV,EendV;

	printf("����ͼ�и�������Ϣ\n");
	for(i=0;i<GM->VertexNum;i++)
	{
		getchar();
		printf("��%d�����㣺",i+1);
		scanf("%c",&(GM->Vertex[i]));
	}

	printf("���빹�ɸ��ߵĶ��㼰Ȩֵ:\n");
	for(k=0;k<GM->EdgeNum;k++)
	{
		getchar();
		printf("��%d���ߣ�",k+1);
		scanf("%c %c %d",&EstartV,&EendV,&weight);
		for(i=0;EstartV!=GM->Vertex[i];i++);
			for(j=0;EendV!=GM->Vertex[j];j++);
			GM->EdgeWeight[i][j] = weight;
			if(GM->GType == 0)
			{
				GM->EdgeWeight[j][i] = weight;
			}
	}
}

void ClearGraph(GraphMatrix *GM)
{
	int i,j;
	for(i=0;i<GM->VertexNum;i++)
	{
		for(j=0;j<GM->EdgeNum;j++)
		{
			GM->EdgeWeight[i][j] = MaxValue;
		}
	}
}

void OutGraph(GraphMatrix *GM)
{
	int i,j;
	for(j=0;j<GM->VertexNum;j++)
	{
		printf("\t %c",GM->Vertex[j]);
	}

	printf("\n");

}

void PrimGraph(GraphMatrix GM)
{
	int i,j,k,min,sum;
	int weight[MaxNum];
	char vtempx[MaxNum];

	sum = 0;
	for(i=1;i<GM.VertexNum;i++)
	{
		weight[i] = GM.EdgeWeight[0][i];
		if(weight[i] == MaxValue)
		{
			vtempx[i] = NoL;
		}
		else
		{
			vtempx[i] = GM.Vertex[0];
		}
	}
	vtempx[0] = USED;
	weight[0] = MaxValue;
	for(i=1;i<GM.VertexNum;i++)
	{
		min = weight[0];
		k = i;
		for(j=1;j<GM.VertexNum;j++)
		{
			if(weight[j] < min && vtempx[j] > 0)
			{
				min = weight[j];
				k = j;
			}
		}
	

	sum += min;
	printf("(%c,%c),",vtempx[k],GM.Vertex[k]);
	vtempx[k] = USED;
	weight[k] = MaxValue;
	for(j=0;j<GM.VertexNum;j++)
	{
		if(GM.EdgeWeight[k][j] < weight[j] && vtempx[j] != 0)
		{
			weight[j] = GM.EdgeWeight[k][j];
			vtempx[j] = GM.Vertex[k];
		}
	}

	}
	printf("\n��С����������ȨֵΪ��%d\n",sum);
}

void main()
{
	GraphMatrix GM;
	char again;
	printf("Ѱ����С��������\n");

S1:
	printf("����������������ͼ�����ͣ�");
	scanf("%d",&GM.GType);
	printf("����ͼ�Ķ���������");
	scanf("%d",&GM.VertexNum);
	printf("����ͼ�ı�������");
	scanf("%d",&GM.EdgeNum);
	ClearGraph(&GM);
	CreateGraph(&GM);
	printf("��ͼ���ڽӾ����������£�");
	OutGraph(&GM);

	printf("��С�������ı�Ϊ��");
	PrimGraph(GM);
S2:
	printf("\n�����棨y/n��?");
	fflush(stdin);
	scanf("%c",&again);
	if(again == 'y' || again =='Y')
	{
		goto S1;
	}
	else if(again == 'n'||again == 'N')
	{
		goto S3;
	}
	else
	{
	  printf("����������������룡\n");
	  goto S2;
	}

S3:
	printf("��Ϸ������\n");

}