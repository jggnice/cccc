#define n 7
#include"stdio.h"
main()
{int i,j,i1,j1,k,a[n+1][n+1];
for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]=0;
i=n;j=(n+1)/2;	a[i][j]=1;

for(k=2;k<=n*n;k++)
{i1=i+1;j1=j+1;
	 if(i1>n&&j1<=n)i1=i1%n;
else if (i1<=n&&j1>n)j1=j1%n;
else if (i1>n&&j1>n){i1=n-1;j1=n;}
else if (i1<=n&&j1<=n&&a[i1][j1]!=0){i1-=2;j1--;}
i=i1;j=j1;a[i][j]=k;


}

for(i=1;i<=n;i++){for(j=1;j<=n;j++)printf("%4d ",a[i][j]);printf("\n\n");}
}