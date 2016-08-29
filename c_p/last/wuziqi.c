#include<stdio.h>
int main()
{
	int i, j, k, count;
	int qq[10][10][192]={0};
	count = 0;
	for(i = 0;  i<10;i++)
		for (j=0 ;j< 6;j++)
			for(k=0; k <5;k++)
				qq[j+k][i][count]=1;
	count ++;
	for(i = 0;  i<10;i++)
	{
			for (j=0 ;j< 10;j++)
			printf("%d",qq[i][j][0]);
			printf("\n");
	}
}