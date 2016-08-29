#include"stdio.h"
main()
{int i,j=0,k;
for(i=100;i>4;i--)
{
	
	k=i;
	while(k%5==0)
	{
		j++;
		k=k/5;
	}
}
printf("%d",j);
}