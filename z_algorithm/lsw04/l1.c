#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main(int argc, char* argv[])
{
	long n=atol(argv[1]),count=0;
	while(n!=1)
	{
			if(n%2==0)
				n=n/2;
			else
				n=3*n+1;
			count++;
	}
	printf("%ld",count);
	return 0;
}