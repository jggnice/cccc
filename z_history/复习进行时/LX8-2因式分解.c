#include"stdio.h"
main()
{int x;int i;
printf("input a number\n\n");
scanf("%d",&x);printf("%d=",x);
for(i=2;i<=x;i++)
	{			while(x%i==0)
		{x=x/i;if(x==1)printf("%d",i);else printf("%d*",i);}
	}getch(); 
}
