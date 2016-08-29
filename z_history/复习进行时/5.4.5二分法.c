/*#include"stdio.h"
#include"math.h"
float f(float a){return(pow(a,3)-pow(a,4)+4*a*a-1);}
main()
{double a=0,b=1,c,d,e=1.0e-6;
c=(a+b)/2;
do{
	if(f(a)*f(c)<0){d=c-a;b=c;}
	else {d=c-b;a=c;}c=(a+b)/2;}
	while(fabs(d)>e);
	printf("%f",c);
}*/


#include"stdio.h"
#include"math.h"
float f(float a){return(pow(a,3)-pow(a,4)+4*a*a-1);}
main()
{double a=0,b=1,c,e=1.0e-12;
while(fabs(b-a)>e){c=(a+b)/2;if(f(c)<0)a=c;else b=c;}printf("%.12f",c);
}