#include"stdio.h"
void main()
{
int m,i,j,k;
int a[10];
for(i=0;i<10;i++)scanf("%d",&a[i]);

for(k=1;k<=9;k++)
{m=a[k];
for(i=0;i<k;i++)if(m<a[i])break;
for(j=k-1;j>=i;j--)a[j+1]=a[j];a[i]=m;
}


for(i=0;i<10;i++)printf("%d  ",a[i]);}
