/*#include"stdio.h"
#include"math.h"
main()
{int x,y=0,x1,x2,c,i=0;
scanf("%d",&x);
x1=x;x2=x;
while(x1>0)
{x1/=10;i++;}
while(x2>0)
{c=x2%10;y+=c*pow(10,i-1);x2/=10;i--;}
if(y==x)
printf("%d是回文数",y);
else
printf("%d不是回文数",y);
}*/





#include"stdio.h"
#include"math.h"
main()
{int x,y=0,x1,i=0;
scanf("%d",&x);x1=x;

while(x1>0){y=y*10+x1%10;x1/=10;}
   
if(y==x)printf("%d是回文数",y);else printf("%d不是回文数",y);
}