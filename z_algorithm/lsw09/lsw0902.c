#include<stdio.h>
#include<stdlib.h>
#define N 4
int table[N][N];
int next[2][(N-1)*(N-1)];
void table_copy(int bb[N][N] , int aa[N][N])
{
	int ii1;
	int jj1;
	for(ii1 = 0; ii1< N; ii1++)
		for(jj1 = 0; jj1< N; jj1++)
			aa[ii1][jj1] = bb[ii1][jj1];
}

void fill(int tab[N][N], int ii, int jj, int kk)
{
	tab[ii][jj]=1;
}
int is_valid(int tab[N][N], int ii, int jj,int kk)
{
	int ii1;
	int flag1=1;
	for(ii1 = 0; ii1 < ii; ii1++)
	{
		if(tab[ii][ii1] == kk)
		{
			flag1=0;
			break;
		}
	}
	for(ii1 = 0; ii1 < jj; ii1++)
	{
		if(tab[ii1][jj] == kk)
		{
			flag1=0;
			break;
		}
	}
	return flag1;
}


void fun(int ta[N][N], int ii, int jj)
{
	int tt[N][N][N];
	int ii1;
	int count_valid = 0;

	for(ii1 = 0; ii1 <N; ii1++)
	{
		table_copy(tt[ii1-1], ta);
		if(is_valid(tt[ii1-1], ii,	jj,	ii1));
		{
			count_valid ++;
			//new table ;
//printf("\n%d\n",count_valid);
			fill(tt[ii1-1],	ii,	jj,	ii1);
			if( ii==N&&jj == N )
			{
				//table_print(tt[ii1-1]);
				printf("\n%d\n",count_valid);
				return;
			}
			fun(tt[ii-1],next[0][ii*3+jj+1],next[1][ii*3+jj+1]);
		}
	}
	if(count_valid == 0)return;
}
int main()
{
	table_init();
	table_print(table);
	fun(table,1,1);

	return 0;
}