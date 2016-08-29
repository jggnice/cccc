#include<stdio.h>
#include<stdlib.h>
#define AMT 10
#define DICE 6

int main()
{
int aa[AMT],ii,jj;
int count=0;

	for(jj=0;jj<AMT;jj++)aa[jj] = 1;
	
	while(aa[0] != DICE +1)
	{
		/* {	
		 for(jj=0;jj<AMT;jj++)
			{
			printf("%d ",aa[jj]);
			}
		printf("\n");
		}  */
		
		aa[AMT-1]++;count++;
		for(ii=AMT-1;ii>=1;ii --)
		{
			if(aa[ii] == DICE +1)
			{
				aa[ii-1]++;				
				for(jj=ii;jj<AMT;jj++)
				{aa[jj]=aa[ii-1];}	
			}
		}		
	}
	printf("\n%d",count);
	return 0;
}