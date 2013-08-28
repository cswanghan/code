#include<stdio.h>
#include<time.h>
#include<stdlib.h>

double MontePI(int n)
{
  double PI;
  double x,y;
  int i,sum;

  sum = 0;
  srand(time(NULL));
  for(i=0;i<n;i++)
  {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		if((x*x + y*y)<1)
			sum++;
  }

  PI = 4.0*sum/n;
  return PI;
}

void main()
{
	int n;
	double PI;

	printf("���ؿ�������㷨����PI��\n");
	printf("������������");
	scanf("%d",&n);
	PI = MontePI(n);
	printf("PI=%f\n",PI);
}