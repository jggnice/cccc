#include"stdio.h"
main()
{int a[100],i,j;
for(i=1;i<100;i++)a[i]=i;
for(j=2;j<100;j++)
for(i=2;i<100;i++)
if(i%j==0&&i>j)a[i]=0;
for(i=2;i<100;i++)if(a[i]!=0)printf("%d ",a[i]);}