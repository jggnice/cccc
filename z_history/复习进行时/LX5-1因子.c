#include"stdio.h"
main()
{int x;int i=1;
printf("input a number\n\n");
scanf("%d",&x);
do 

	{if(x%i==0)printf("%d ",i);
		i++;}
while(i<=x);
}