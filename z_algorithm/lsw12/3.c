#include"stdio.h"
#include"stdlib.h"
#define Pow 20131206
#define Mode 9527
int main(int argc, char** argv)
{
	FILE *fp1;
int sum = 1;
int i;
for(i=0; i<Pow; i++)
{
	sum = (sum*2)%Mode;	
}
printf("%d\n",sum);
return 0;
}