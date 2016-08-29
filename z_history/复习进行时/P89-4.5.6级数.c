#include"stdio.h"
main()
{double sum=0,i=2,j,x;
printf("input x>1\n\n");
scanf("%lf",&x);j=1;
do
{sum+=j;j/=x;i++;}
while(j>1.0e-6);
printf("sum=%.6f",sum);
}