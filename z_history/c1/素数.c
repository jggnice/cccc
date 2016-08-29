#include"stdio.h"
void fun(int m,int k,int *xx)
{int i,j,flag,k1=0;
for(i=m+1;k1<=k;i++)
	{flag=0; for(j=2;j<i;j++)
	if(i%j==0)flag++;
	if(!flag)xx[k1++]=i;
	}
}
main()
{int m,k,xx[100],i;
scanf("%d %d",&m,&k);
fun(m,k,xx);
for(i=0;i<k;i++)printf("%d ",xx[i]);
}