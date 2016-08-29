#include"stdio.h"
main()
{int d,x,a=2,s=0;int i=1;


for(a=2;a<=100;a++)
	{for(i=1;i<a;i++)
		{d=a%i;if(d==0)s=s+i;}
x=s;if(x==a)printf("%d\n",a);s=0;}
}