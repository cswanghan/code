#include<stdio.h>

int Fibonacci(int n)
{
	int t1,t2;

	if(n == 1 || n == 2)
	{
		return 1;
	}
	else {
		t1 = Fibonacci(n-1);
		t2 = Fibonacci(n-2);
		return t1+t2;
	}
}

void main()
{
	int n,num;

	printf("�����㷨������Ӳ������⣡\n");
	printf("��������ʱ�䣺");
	scanf("%d",&n);
	num = Fibonacci(n);
	printf("����%d�µ�ʱ�䣬���ܷ�ֳ��%d�����ӣ�\n",n,num);
}