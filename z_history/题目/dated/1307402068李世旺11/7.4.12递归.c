#include"stdio.h"

int sum(int x,int i)
{int s;if(i==1)s=x;else s=sum(x,i-1)*x;return s;}
main()
{int i,x;
scanf("%d%d",&x,&i);
printf("%d",sum(x,i));}

