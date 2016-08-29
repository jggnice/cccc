
#include"stdio.h"
void fun(int a[],int p,int n)
{	int t,j;
if(p==1){t=a[0];for(j=1;j<n;j++){a[j-1]=a[j];}a[n-1]=t;}
	else 
	{t=a[0];for(j=1;j<n;j++){a[j-1]=a[j];}a[n-1]=t;fun(a,p-1,n);}		
}
main()
{int a[100],i,p1,n;
printf("数组长度？");scanf("%d",&n);
printf("移多少个？");scanf("%d",&p1);
for(i=0;i<n;i++)a[i]=i+1;
fun(a,p1,n);
for(i=0;i<n;i++)printf("%d ",a[i]);}