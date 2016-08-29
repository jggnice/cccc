#include"stdio.h"

int sum(int i)
{int s;if(i==1)s=1;else s=sum(i-1)+i;return s;}
main()
{int i;
scanf("%d",&i);
printf("%d",sum(i));}
