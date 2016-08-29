#include"stdio.h"

main()
{
	float x;int a;
	printf("input a grade");
	scanf("%f",&x);
	a=(int)(x/10);
	switch(a)
	{
	case 10:
	case 9:printf("A");break;
	case 8:printf("B");break;
	case 7:printf("C");break;
	case 6:printf("D");break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:printf("E");break;
	default: printf("ÊäÈëÊı¾İ´íÎó");}}