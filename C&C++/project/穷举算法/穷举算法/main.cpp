#include<stdio.h>

int qiongju(int head,int foot,int *chicken,int *rabbit)
{
	int re,i,j;
	re = 0;
	for(i=0;i<=head;i++)
	{
		j = head - i;
			if(i*2 + j*4 == foot){
				re = 1;
				*chicken = i;
				*rabbit = j;
				
			}
	}
	return re;
}

void main()
{
	int chicken,rabbit,head,foot;
	int re;

	printf("��ٷ���⼦��ͬ�����⣺\n");
	printf("����ͷ����");
	scanf("%d",&head);
	printf("���������");
	scanf("%d",&foot);

	re = qiongju(head,foot,&chicken,&rabbit);

	if(re == 1)
	{
		printf("���У�%dֻ�������У�%dֻ��\n",chicken,rabbit);
	}
	else{
	  printf("�޷���⣡\n");
	}
}