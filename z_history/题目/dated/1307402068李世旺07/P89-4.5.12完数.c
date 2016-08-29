#include"stdio.h"
main()
{int d,x,a=2,s=0;int i=1;

/*do
{
while(i<y)
	{if(y%i==0)s+=i;
		i++;}
if(s==y)printf("%d\n",s);
s=0;

y++;}
while(y<=100);
}*/
for(a=2;a<=100;a++)
	{for(i=1;i<a;i++)
		{d=a%i;if(d==0)s=s+i;}
x=s;if(x==a)printf("%d\n",a);s=0;}
}