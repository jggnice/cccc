#include<stdio.h>

int main()
{
	int x,y,count=0;
	for(x=0; x<=23; x++)
		for(y=0; y<=23; y++)
		{
			if(23-x-y>=0)
			{
				printf("%d %d %d\n",x,y,23-x-y);
				count++;
			}
		}
		printf("%d",count);
		return 0;
}