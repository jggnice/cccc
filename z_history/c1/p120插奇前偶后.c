#include"stdio.h"
main()
{
int m,i,j,k;
int a[10]/*={10,9,8,7,6,5,4,3,2,1}*/;
for(i=0;i<10;i++)scanf("%d",&a[i]);

for(k=1;k<=9;k++)
{m=a[k];
	if(m%2!=0){for(j=k-1;j>=0;j--)a[j+1]=a[j];a[0]=m;}
}


for(i=0;i<10;i++)printf("%d  ",a[i]);
}