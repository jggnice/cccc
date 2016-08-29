#include"stdio.h"
main()
{int x;int i;
printf("input a number\n\n");
scanf("%d",&x);
for(i=2;i<=x;i++)
	{			if(x%i==0)printf("%d ",i);while(x%i==0)
		{x=x/i;}
	}
}