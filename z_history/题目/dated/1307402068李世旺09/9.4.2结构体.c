#include"stdio.h"
struct djt
{int day;int month;int year;};
main()
{int dayof[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct djt date,*p;
int i,d;
printf("please input the year,month and day");
scanf("%d%d%d",&date.year,&date.month,&date.day);
p=&date;
if(p->year==0)printf("error in year");
else {if((date.year%4==0&&date.year%100!=0)||(date.year%400==0))dayof[2]=29;
d=date.day;
for(i=1;i<p->month;i++)d+=dayof[i];}printf("%d\n",d);
}