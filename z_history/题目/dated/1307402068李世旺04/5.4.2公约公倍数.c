#include"stdio.h"
main()
{int p,r,n,m,k;
scanf("%d,%d",&m,&n);
p=m*n;r=m%n;
while(r!=0)
{m=n;n=r;r=m%n;}
printf("���ǵ����Լ��%d",n);
	   k=p/n;
printf("���ǵ���С������%d",k);
}