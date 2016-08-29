#include"stdio.h"
int is_prime(int n)
{int p,i;
	for(i=2;i<n;i++)
{if(n%i==0)break;}
if(i==n)p=1;
else p=0;
return p;
}
main()
{int n;
scanf("%d",&n);
if(is_prime(n)==1)printf("素数");
else printf("不是素数");
}