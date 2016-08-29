#include"stdio.h"
int factor(int a[],int x)
{int i,j=0;for(i=1;i<x;i++)if(x%i==0){a[j]=i;j++;};return j;}

main()
{int i,y,j,a[1000];
scanf("%d",&y);
j=factor(a,y);
for(i=0;i<j;i++)printf("%d ",a[i]);}
