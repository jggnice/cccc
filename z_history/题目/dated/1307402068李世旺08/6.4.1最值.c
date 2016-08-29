#include"stdio.h"
main()
{ float max1,min1;float a[10];int i;
for(i=0;i<10;i++)scanf("%f",&a[i]);

max1=a[0]; min1=a[0];
for(i=1;i<10;i++)
{if(max1<a[i])max1=a[i];
if(min1>a[i])min1=a[i];}
printf("%f,%f\n",max1,min1);}