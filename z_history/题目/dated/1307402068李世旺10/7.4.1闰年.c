#include"stdio.h"
int is_run(int y)
{return (y%4==0&&y%100||y%400==0);}
main()
{int y;
	scanf("%d",&y);
if(is_run(y)==1)
printf("YES闰年");
else printf("不是闰年");
}