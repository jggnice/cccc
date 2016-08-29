#include"stdio.h"
main()
{int a[10],t;int i,j,N,c;
printf("1 for up;0 for down");scanf("%d",&c);
printf("how many?");scanf("%d",&N);
for(i=0;i<N;i++)scanf("%d",&a[i]);


for(j=0;j<N-1;j++)


for(i=j+1;i<N;i++)
if(c==1){if(a[j]>a[i]){t=a[i];a[i]=a[j];a[j]=t;}}
else {if(a[j]<a[i]){t=a[i];a[i]=a[j];a[j]=t;}}



for(i=0;i<N;i++)printf("%d ",a[i]);}