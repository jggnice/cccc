#include<stdio.h>
int main()
{
	int value;
	int ii;
	for(ii = 0;ii < 9*2-1; ii ++)
	{
		scanf("%d",&value);
		printf("%d,",value);
		if(ii%2)printf("\n");
	}
	scanf("%d",&value);
	printf("%d",value);
	return 0;
}