#include"stdio.h"
void BubbleSort(int a[],int n)
{int i,j,t;
for(j=1;j<=n-1;j++)
for(i=0;i<=n-1-j;i++)
if(a[i]>a[i+1]){t=a[i];a[i]=a[i+1];a[i+1]=t;}
}
main()
{int Arr[100],i,n;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&Arr[i]);
BubbleSort(Arr,n);
for(i=0;i<n;i++)printf("%d ",Arr[i]);

}