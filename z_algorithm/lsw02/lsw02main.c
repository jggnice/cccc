#include"stdio.h"
#include"lsw02.h"


int main()
{
	long m,n;
	int i;
	fen m1,sum1,sum2;
	printf("\n�����������������Լ��:");
	scanf("%d%d",&m,&n);
	printf("\n���Լ��:%d",gcd(m,n,1));
	
	printf("\n����������������С������:");
	scanf("%d%d",&m,&n);
	printf("\n��С������:%d",gcd(m,n,2));
	
	sum1.aa=0;sum1.bb=1;sum2=sum1;
	m1.aa=1;m1.bb=1;
	for(i=1;i<=17;i++)
	{
		sum1=addfen(sum1,m1);
		(m1.bb)++;
	}
	printf("\nsum1=");fen_print(sum1);
	//sum1 finished
	m1.aa=1;m1.bb=1;
	for(i=1;i<=17;i++)
	{
		sum2=addfen(sum2,m1);
		m1.aa=-m1.aa;(m1.bb)++;
	}
	printf("\nsum2=");fen_print(sum2);
	//sum2 finished
	
	return 0;
}
