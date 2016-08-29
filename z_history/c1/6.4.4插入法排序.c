#include"stdio.h"

main()
{int a[10],i,j,t;
for(i=0;i<10;i++){scanf("%d",&a[i]);}


for(i=1;i<10;i++)
{t=a[i];for(j=i-1;j>=0&&t<a[j];j--)a[j+1]=a[j];a[j+1]=t;}



for(i=0;i<10;i++)printf("%d ",a[i]);
}  