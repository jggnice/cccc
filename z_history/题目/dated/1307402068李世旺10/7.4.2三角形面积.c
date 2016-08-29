#include"stdio.h"
#include"math.h"
double f(double a,double b,double c)
{double p;
p=(a+b+c)/2;
p=sqrt(p*(p-a)*(p-b)*(p-c));
return p;}
main()
{double a,b,c;
scanf("%lf%lf%lf",&a,&b,&c);
printf("%f",f(a,b,c));
}