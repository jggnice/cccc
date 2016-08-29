#include"stdio.h"

main()
{int a[100],t;int i,j,N;
printf("how many?");scanf("%d",&N);
for(i=0;i<N;i++)scanf("%d",&a[i]);
for(j=1;j<=N-1;j++)
for(i=0;i<=N-1-j;i++)
if(a[i]>a[i+1]){t=a[i];a[i]=a[i+1];a[i+1]=t;}
for(i=0;i<N;i++)printf("%d ",a[i]);}