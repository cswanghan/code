#include<stdio.h>

long fact(int n);

void main()
{
	int i;
	printf("������Ҫ��׳˵�һ��������");
	scanf("%d",&i);
	printf("%d�Ľ׳˽��Ϊ��%ld\n",i,fact(i));            //n=32ʱ���
}

long fact(int n)
{
	if(n<=1)
		 return 1;
	else return n*fact(n-1);
}