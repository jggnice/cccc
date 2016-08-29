#include"stdio.h"
main()
{double sum=0,i=2,j,x;
printf("input x");
scanf("%lf",&x);j=x;
do
{sum+=j;j*=x/i;i++;}
while(j>1.0e-6);
printf("sum=%.6f",sum);
}