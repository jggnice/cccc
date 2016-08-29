#include"stdio.h"

main()
{
	float x,y;
	scanf("%f",&x);
	if(x<1)
		y=x;

else if(x>=5&&x<10)
{y=2*x-1;printf("y=%f",y);}
else if(x>10&&x<15)
{y=3*x+4;printf("y=%f",y);}
else if(x>20&&x<30)
{y=90-5*x;printf("y=%f",y);}
else if(x>60)
{y=80+3*x;printf("y=%f",y);}
else printf("²»ÔÚ·¶Î§ÄÚ");

}
