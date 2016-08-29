#define n 10
#define p1 3
#include"stdio.h"
void fun(int a[],int p)
{	int t,i,j;
	for(i=0;i<=p;i++)
	{t=a[0];
		for(j=1;j<n;j++){a[j-1]=a[j];}
	a[n-1]=t;}		
}
main()
{int a[n],i;
for(i=0;i<n;i++)a[i]=i+1;
fun(a,p1);
for(i=0;i<n;i++)printf("%d ",a[i]);}