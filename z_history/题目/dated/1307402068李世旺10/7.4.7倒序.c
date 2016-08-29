#include"stdio.h"
#include"math.h"
int reverse(int x)
{int y=0,x1,x2,i=0,c;

x1=x;
x2=x;
	while(x1>0)
	{x1=x1/10;i++;}
	while(x2>0)
	{c=x2%10;y=y+c*pow(10,i-1);x2=x2/10;i--;}
	return(y);
}
main()
{int w;
scanf("%d",&w);
printf("%d==>%d",w,reverse(w));
}

