#include"stdio.h"
int main()
{int i=0,j,sum=0,a[100];char ch;
char aa[][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	while((ch=getchar())!='\n')
		sum+=ch-'0';
	if(sum==0){printf("%s",aa[0]);return 0;}
	while(sum>0)
	{
		a[i++]=sum%10;
		sum/=10;
	}
	for(j=i-1;j>=0;j--)
	{
if(j==i-1)printf("%s",aa[a[j]]);
else		printf(" %s",aa[a[j]]);
	}
return 0;
}
