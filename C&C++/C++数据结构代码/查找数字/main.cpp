#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(){
	int arr[N],x,i;
	int f = -1;
	
	srand(time(NULL));
	for(i=0;i<N;i++){
	arr[i]=rand()/1000;
	}

	printf("����Ҫ���ҵ�������");
	scanf("%d",&x);

	for(i=0;i<N;i++){
		if (x == arr[i]) {
		   f=1;
		   break;
		}
	}
	printf("\n ������ɵ��������У�\n");
	for(i=0;i<N;i++){
		printf("%d",arr[i]);
	}
	printf("\n\n");

	if(f<0)
	{
		printf("û�ҵ����ݣ�%d\n",x);
	}else{
		printf("���ݣ�%dλ������ĵ�%d��Ԫ�ش�.\n",x,f+1);
	}
	system("pause");
	return 0;




}
