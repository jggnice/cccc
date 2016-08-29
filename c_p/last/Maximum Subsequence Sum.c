#include"stdio.h"

int main()
{
 int i,j,fi,fj,sum=0,t=0,count=0,flag1=0,flag2=0;int A[10001];register int k;
 scanf("%d",&A[0]);
for(i=1;i<=A[0];i++)
{scanf("%d",&A[i]);}
for(i=1;i<=A[0];i++)
{if(A[i]==0)flag1=1;if(A[i]>0)flag2=1;}
//printf("\n%d %d\n",flag1,flag2);
if((flag2==0)&&(flag1==0)){printf("%d %d %d",0,A[1],A[A[0]]);return 0;}
if((flag2==0)&&(flag1==1)){printf("0 0 0");return 0;}

for(i=1;i<=A[0];i++)
for(j=i;j<=A[0];j++)
{t=0;
for(k=i;k<=j;k++)
t+=A[k];
if(t>sum)
{sum=t;fi=i;fj=j;/*printf("--%d--",sum);*/}
}

printf("%d %d %d",sum,A[fi],A[fj]);

return 0;
} 
