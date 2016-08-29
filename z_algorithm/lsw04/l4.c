#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main(int argc, char* argv[])
{
	long m=atol(argv[1]),count=3,flag=1;
	long oldf=1;
	long newf=1;
	long tep;
	
	if(m<=1){printf("0");return 0;}
	
	tep=newf;newf=(oldf+newf)%m;oldf=tep;if(newf==1){printf("0");return 0;}
	
	while(flag)
	{
		tep=newf;newf=(oldf+newf)%m;oldf=tep;if((oldf==1)&&(newf==1)){flag=0;}
		count++;
	}
	
	printf("%ld",count-2);
	return 0;
}