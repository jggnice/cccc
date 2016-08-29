#include"stdio.h"
main()
{int p,r,n,m,k;
scanf("%d,%d",&m,&n);
p=m*n;r=m%n;
while(r!=0)
{m=n;n=r;r=m%n;}
printf("他们的最大公约数%d",n);
	   k=p/n;
printf("他们的最小公倍数%d",k);
}