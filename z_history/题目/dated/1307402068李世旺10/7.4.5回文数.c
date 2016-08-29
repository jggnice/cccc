#include"stdio.h"
#include"math.h"
int h(int z)
{int p,y=0,x1,x2,i=0,c;

x1=z;
x2=z;
	while(x1>0)
	{x1=x1/10;i++;}
	while(x2>0)
	{c=x2%10;y=y+c*pow(10,i-1);x2=x2/10;i--;}
	if(y==z)p=1;else p=0;
	return p;
		
     
}
main()
{int x;
scanf("%d",&x);
if(h(x)==1)printf("yes\n");
else printf("no\n");}