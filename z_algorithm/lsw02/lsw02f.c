#include"stdio.h"
#include"lsw02.h"

//���Լ������С������
long gcd(long m,long n,int t)
{	long m1=m,n1=n;
	
	if(m1*n1==0)n1=m1+n1;
	else 
	{
		long r=m1%n1;
		while(r!=0){m1=n1;n1=r;r=m1%n1;}
	}
	if(n1<0)n1=-n1;
	//n1�����Լ����
	if(t==1)return n1;
	else return m*n/n1;
}
//Լ�ֵĺ���
void yuefen(fen *a1)
{
	long r,m=(*a1).bb,n=(*a1).aa;
	if(a1->aa==0){a1->bb=1;return;}
	
	r=m%n;										//��mСʱ�������m���n��С
	while(r!=0){m=n;n=r;r=m%n;}
														//n�����Լ����
	(*a1).bb/=n;(*a1).aa/=n;
	return;
}
//�����ӷ�
fen addfen(fen a1,fen a2)
{
	fen a3;
	a3.aa=(a1.aa)*(a2.bb)+(a1.bb)*(a2.aa);
	a3.bb=(a1.bb)*(a2.bb);
	yuefen(&a3);
	return a3;
}
void fen_print(fen a1)
{
	printf("%ld/%ld",a1.aa,a1.bb);
}