#include"stdio.h"
main()
{int x,y,sum,cj;
int *px,*py;
px=&x;py=&y;
printf("enter two integers:\n");
scanf("%d%d",px,py);
sum=*px+*py;
cj=*px**py;
printf("%d %d",sum,cj);}