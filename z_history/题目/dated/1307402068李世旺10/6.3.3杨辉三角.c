#include"stdio.h"
main()
{int a[6][6],i,j;
for(i=0;i<6;i++)
for(j=0;j<6;j++)a[i][j]=0;

for(i=0;i<6;i++)a[i][0]=1;

for(i=1;i<6;i++)
for(j=1;j<=i;j++)
a[i][j]=a[i-1][j-1]+a[i-1][j];

for(i=0;i<6;i++)
{for(j=0;j<6-(i-1);j++)printf(" ");
for(j=0;j<=i;j++)printf("%d ",a[i][j]);
printf("\n");}}





