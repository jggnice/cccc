#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main(int argc, char* argv[])
{
	long n=87539319,i,j;
	long limit=1+(long)pow(87539319.0,1.0/3.0);
	for(i=0;i<=limit;i++)
		for(j=i;j<limit;j++)
			if(i*i*i+j*j*j==n)
				printf("%d %d\n",i,j);
	
	return 0;
}