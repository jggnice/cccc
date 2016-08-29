#include"stdio.h"
float p(int n,float x)
{float s;
if(n==0)s=1;else if(n==1)s=x;
else s=p(n-1,x)*(2*n-1)-(n-1)*p(n-2,x);
return s;}
main()
{int n;float x;
scanf("%d%f",&n,&x);
printf("%f",p(n,x));}