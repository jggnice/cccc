#include<stdio.h>
#include<stdlib.h>
#define M 20
#define N 25
int table[M][N];
int count_edge = 0;
void fill(int ii,int jj)
{
	table[ii][jj]=1;
}
int is_valid(int ii, int jj)
{
	if(ii>=0&&ii<M&&jj>=0&&jj<N)
		return 1;
	else return 0;
}
int is_filled(int ii,int jj)
{
	if(table[ii][jj])
		return 1;
	else return 0;
}
void fun(int ii,int jj)
{int sum;
int ii1,jj1;
	if(!is_valid(ii,jj))return;
	else
	{
		count_edge++;
		if(is_filled(ii,jj))return;
		else
		{
		fill(ii,jj);
		sum=ii+jj;
		ii1=M-1;fun(ii1,jj);
		jj1=N-1;fun(ii,jj1);
		ii1=0;fun(ii1,jj);
		jj1=0;fun(ii,jj1);
		ii1=M-1;jj1=sum-ii1;fun(ii1,jj1);
		ii1=sum;jj1=sum-ii1;fun(ii1,jj1);
		jj1=N-1;ii1=sum-jj1;fun(ii1,jj1);
		jj1=sum;ii1=sum-jj1;fun(ii1,jj1);
		}
	}
}
int table_print()
{
	int ii,jj;
	int count_point=0;
	for(ii=0;ii<M;ii++)
	{
		for(jj=0;jj<N;jj++)
		{
			printf("%d ",table[ii][jj]);
			if(table[ii][jj])count_point++;
		}
		printf("\n");
	}
	return count_point;
}
void table_init()
{
	int ii,jj;
	for(ii=0;ii<M;ii++)
	for(jj=0;jj<N;jj++)
		table[ii][jj]=0;
}
int main()
{
	int count_point;
	table_init();
	fun(0,0);
	count_point = table_print();
	printf("\ncount_point = %d",count_point);
	printf("\ncount_edge = %d",count_edge);
	return 0;
}
