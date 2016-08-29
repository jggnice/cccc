#include"stdio.h"
main()
{int year,month,day;
printf("input year,month");
scanf("%d,%d",&year,&month);
if(month==2)
{if(year%4==0&&year%100!=0||(year%400==0)) 
day=29;
else day=28;}
else switch(month)
{case 4:
case 6:
case 9:
case 11:day=30;break;
default:day=31;}
printf("%d",day);}
