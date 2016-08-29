#include"stdio.h"
#include"math.h"
main()
{
	float a,b,c,q,x1,x2;
	scanf("%f,%f,%f",&a,&b,&c);
	q=b*b-4*a*c;
	if(q>=0)
	{x1=(-b+sqrt(b*b-4*a*c))/2/a,x2=(-b-sqrt(b*b-4*a*c))/2/a;
	printf("x1=%f,x2=%f",x1,x2);}
else printf("ÎÞÊµ¸ù");
}

