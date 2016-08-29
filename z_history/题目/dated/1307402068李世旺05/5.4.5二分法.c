#include"stdio.h"
#include"math.h"
main()
{double a=0,b=1,c,d,e=1.0e-6;
c=(a+b)/2;
do{
	if((pow(a,3)-pow(a,4)+4*a*a-1)*(pow(c,3)-pow(c,4)+4*c*c-1)<0){d=c-a;b=c;}
	else {d=c-b;a=c;}c=(a+b)/2;}
	while(fabs(d)>e);
	printf("%f",c);
}
