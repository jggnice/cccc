#include"stdio.h"
main()
{int i=0,j=0,k=0;
for(i=0;i<=20;i++)
for(j=0;j<=34;j++)
for(k=0;k<=300;k++)
{if(5*i+3*j+k/3==100&&i+j+k==100)printf("big%dmiddle%dsmall%d\n",i,j,k);}
}