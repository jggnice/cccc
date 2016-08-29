#include"stdio.h"
main()
{int x=100,a,b,c;
	do
	{a=x%10;b=(x/10)%10;c=(x/100)%10;
	if(a>b&&b>c)
		printf("%d\n",x);
	x++;}
	while(x<1000);}