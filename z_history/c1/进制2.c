#include"stdio.h"//针对已知格式的进制%x %o %d有效
#include"math.h"
#include"conio.h"
#include"stdlib.h"
#define N 16
main()
{int x1,i,y,k=0;FILE * fp;

if((fp=fopen("D:\\myhuiwen16.txt","wt"))==NULL){printf("no such thing");getch();exit(1);}

for(i=0;i<pow(N,3);i++)
	{x1=i;y=0;
		while(x1>0)
		{y=y*N+x1%N;x1/=N;}
	
if(y==i){k++;printf("%-10x",i);fprintf(fp,"%-10x",i);if(k%5==0){printf("\n");fprintf(fp,"\n");}}

	}	fclose(fp);
}