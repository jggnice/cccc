#include"stdio.h"
#include"math.h"
main()
{int x,y=0,x1,x2,i=0,c;
scanf("%d",&x);
x1=x;
x2=x;
	while(x1>0)
	{x1=x1/10;i++;}
	while(x2>0)
	{c=x2%10;y=y+c*pow(10,i-1);x2=x2/10;i--;}
	if(y==x)
		printf("yes\n");
     else printf("no\n");
}