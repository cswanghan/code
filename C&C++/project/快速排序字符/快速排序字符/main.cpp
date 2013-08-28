#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void kuaisu(char *a,int left,int right)
{
	int f,l,r,t;
	l=left;
	r=right;
	f=a[(left+right)/2];

	while(l<r)
	{
		while(a[l]<f)  ++l;
		while(a[r]<f)  --r;

		if(l<=r)
		{
			t=a[l];
			a[l]=a[r];
			a[r]=t;
			++l;--r;
		}
	}
	if(l == r)
		l++;
	if(left < r)
	{
		kuaisu(a,left,l-1);   //�ݹ����
	}
	if(l<right)
	{
		kuaisu(a,r+1,right);  //�ݹ����
	}
}

int mian()
{
	char str[80];
	int N;

	memset(str,'\0',sizeof(str));

	printf("����һ���ַ���:");
	scanf("%s",str);   //�����ַ���

	N=strlen(str);

	printf("����ǰ��\n");
	printf("%s\n",str);   //���

	kuaisu(str,0,N-1);   //����

	printf("�����\n");
	printf("%s\n",str);  //���

	system("pause");

	return 0;
}