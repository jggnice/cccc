#include"stdio.h"

main()
{
	int x;
	
	scanf("%d",&x);
	
	switch(x)
	{
	case 13:printf("K");break;
	case 1:printf("A");break;
	case 10:printf("T");break;
	case 11:printf("J");break;
	case 12:printf("Q");break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 6:
    case 7:
	case 8:
	case 9:	printf("%d",x);break;
	default: printf("ÊäÈëÊı¾İ´íÎó");}}