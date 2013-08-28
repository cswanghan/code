#include<iostream>
#include<time.h>
#include <stdlib.h>
#include<cmath>
using namespace std;

const int M=8,T=2;        //  M Ⱥ���С��pc �������,pm �������,T ��ֹ����
const double pc=0.6,pm=0.01;

struct population        //����Ⱥ��ṹ
{int x[20];
 double x1,x2;
 double fit;
 double sumfit;
}p[M];

void initial(population *);                //��ʼ������
void evaluefitness(population *);          // ������Ӧ��
void select(population *);                 // ѡ���ƺ���
void crossover(population *);              // ���溯��
void mutation(population *);               // ���캯��
void decoding(population *);               // ���뺯��
void print(population *);                  //��ʾ����

int main()                                //�Ŵ��㷨������
{int gen=0;
 initial(&p[0]);                          //�����ó�ʼ��
 cout<<"initialed!"<<endl;
 print(&p[0]);
 decoding(&p[0]);                      //�Ƚ���
  cout<<"decoded!"<<endl;
  print(&p[0]);
  evaluefitness(&p[0]);                  //������Ӧֵ���ۼ���ֵ
  cout<<"evalued!"<<endl;
  print(&p[0]);
 while(gen<=T)
 {cout<<"gen="<<gen+1<<endl;
  select(&p[0]);
  decoding(&p[0]); 
  evaluefitness(&p[0]); 
  cout<<"selected!"<<endl;
  print(&p[0]);
  crossover(&p[0]);
  decoding(&p[0]); 
  evaluefitness(&p[0]); 
  cout<<"crossovered!"<<endl;
  print(&p[0]);
  mutation(&p[0]);
  decoding(&p[0]); 
  evaluefitness(&p[0]); 
  cout<<"mutated!"<<endl;
  print(&p[0]);
  gen++;
 }
 decoding(&p[0]);
 evaluefitness(&p[0]);
 cout<<"���ó��������Ϊ:"<<endl;
 for(int i=0;i<M;i++)
	 cout<<"x1:"<<p[i].x1<<"  x2:"<<p[i].x2<<"  ֵ: "<<p[i].fit<<endl;  
return 0;
}
/*****************************��ʼ������*****************************/
int rand01()               //�������ȡ0��1�ĺ���
{int r;
 float q;
 q=rand()/(RAND_MAX+0.0);
 if(q<0.5)  r=0;
 else       r=1;
 return r;
}
 
void initial(population *t) //Ⱥ���ʼ������
{int j;
 population *po;
 srand(time(0));
 for(po=t;po<t+M;po++)
   for(j=0;j<20;j++)
    (*po).x[j]=rand01();
}

/*************************������Ӧֵ����*********************************/
void evaluefitness(population *t)           //������Ӧֵ����
{double f,x1,x2,temp=0.0;
 population *po,*po2;
 for(po=t;po<t+M;po++)
 {x1=(*po).x1;
 x2=(*po).x2;
 f=100.0*(x1*x1-x2*x2)*(x1*x1-x2*x2)+(1.0-x1)*(1.0-x1);
 (*po).fit=f;
 }
 for(po=t;po<t+M;po++)                     //�����ۼ���Ӧֵ
 {for(po2=t;po2<=po;po2++)
    temp=temp+(*po2).fit;
 (*po).sumfit=temp;
 temp=0.0;
 }
}

/**************************ѡ���ƺ���********************************/
double randab(double a,double b)        //������(a,b)������һ�������
{double c,r;
 c=b-a;
 r=a+c*rand()/(RAND_MAX+1.0);
 return r;
}
 
void select(population *t)              //ѡ�����Ӻ���
{int i=0;
 population pt[M],*po;
 double s;
 srand(time(0));
 while(i<M)
 {s=randab((*t).sumfit,(*(t+M-1)).sumfit);             
  for(po=t;po<t+M;po++)
  {if((*po).sumfit>=s) {pt[i]=(*po);break;}
   else continue;
  }
  i++;
 }
 for(i=0;i<M;i++)                      //�����ƺ�����pt[M]ת��p[M]
	 for(int j=0;j<20;j++)
		 p[i].x[j]=pt[i].x[j];
}

/***************************���溯��*******************************/
void crossover(population *t)        //�������Ӻ���
{population *po;
 double q;                      //���ڴ�һ��0��1�������
 int d,e,tem[20];                     //d��Ŵ�1��19��һ���������������ȷ�������λ��
          //e��Ŵ�0��M��һ��������뵱ǰP[i]��i��ͬ������������ȷ������Ķ���
 srand(time(0));
 for(po=t;po<t+M/2;po++)
 {q=rand()/(RAND_MAX+0.0);
  if(q<pc)
  {for(int j=0;j<M;j++)          //����M�Σ��������Ⱥ����ĳ�������Լ���������
  {e=rand()%M;                  //���ȷ���������
  if(t+e!=po) break;}           //�����ظ�
   d=1+rand()%19;               //���ȷ������λ��
   for(int i=d;i<20;i++)
   {tem[i]=(*po).x[i];
    (*po).x[i]=(*(t+e)).x[i];
	(*(t+e)).x[i]=tem[i];
   }
  }
    else continue;
 }
}
 
/***************************���캯��*******************************/
void mutation(population *t)      //�������Ӻ���
{double q;                     //q����������ÿһ��������������[0��1]�������
 population *po;
 srand(time(0));
 for(po=t;po<t+M;po++)
 {   int i=0;
	 while(i<20)
 {q=rand()/(RAND_MAX+0.0);           
  if(q<pm) (*po).x[i]=1-(*po).x[i];
  i++;
 }
 }
}
  
/***************************���뺯��*******************************/
void decoding(population *t)        //���뺯��
{population *po;
 int temp,s1=0,s2=0;
 float m,n,dit;
 n=ldexp(1,10);                  //n=2^10
 dit=4.096/(n-1);                //dit=(U(max)-U(min))/n-1
 for(po=t;po<t+M;po++)
 {for(int i=0;i<10;i++)
 {temp=ldexp((*po).x[i],i);
 s1=s1+temp;}
 m=-2.048+s1*dit;
 (*po).x1=m;
 s1=0;
 for(int j=10;j<20;j++)
 {temp=ldexp((*po).x[j],j-10);
 s2=s2+temp;}
 m=-2.048+s2*dit;
 (*po).x2=m;
 s2=0;
 }
}
 
/*******************************��ʾ����**************************************/
void print(population *t)
{population *po;
for(po=t;po<t+M;po++)
{for(int j=0;j<20;j++)
	{cout<<(*po).x[j];
if((j+1)%5==0) cout<<"  ";}
  cout<<endl;
  cout<<(*po).x1<<"  "<<(*po).x2<<"  "<<(*po).fit<<"  "<<(*po).sumfit<<endl;
}
}