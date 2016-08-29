#include"stdio.h"
main()
{int a[10],t;int i,j;
for(i=0;i<10;i++)scanf("%d",&a[i]);


for(j=0;j<=8;j++)


for(i=j+1;i<=9;i++)
if(a[i]<a[j]){t=a[i];a[i]=a[j];a[j]=t;}




for(i=0;i<10;i++)printf("%d ",a[i]);}