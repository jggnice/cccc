#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lsw03.h"
int main(int argc, char* argv[])
{
 FILE *fp;
 char tep[1200],sum0[1200]="0";
 int n,signofnew=0,signofold=0;

//*********************checkblock***********************************
 //check parameters
 if(argc<2){printf("not enough parameters");system("pause");return 0;} 
 //check file
 if ((fp = fopen(argv[1], "rt")) == NULL)
   {printf("Can't open file.\n");system("pause");exit(EXIT_FAILURE);}
printf("\n%s",argv[0]);
printf("\n%s",argv[1]);
//*********************checkblock***********************************
fscanf(fp,"%d",&n);									//number of numbers		
	while(n>0)
	{
		fscanf(fp,"%s",tep);	n--;					//  signed number  tep
		signofnew=getstrnumber(tep);			//  unsigned number tep
		//*********************************************************
		if((signofnew)&&(signofold))
		{
			//两个负数相加
			//  unsigned number tep and sum0
			signofold=1;
			//printf("\nthe answer is \n");
			BigAdd(sum0,tep,sum0);//system("pause");
		}
		//*********************************************************		
		else if((signofnew)||(signofold))
		{
			//  unsigned number tep and sum0
			//  assume that signofold=0;
			signofold=0;
			if(comparestr(sum0,tep)>=0)
			{
				if(!signofnew)
				signofold=1;
				
				
				//printf("\nthe answer is \n");
				BigSub(sum0,sum0,tep);
				//system("pause");
				
				
			}
			else
			{
				if(signofnew)
				signofold=1;
				
				//printf("\nthe answer is \n");
				BigSub(sum0,tep,sum0);//system("pause");				
				
			}
		}
		//*********************************************************		
		else
		{
			//两个正数相加
			//  unsigned number tep and sum0
			signofold=0;
			//printf("\nthe answer is \n");
			BigAdd(sum0,tep,sum0);			
			//system("pause");
		}
	}
//**************************block***********************************
		printf("\nthe answer is\n");
		if(get_in_the_end(sum0)==1)printf("0");
		else
		{
			if(signofold==1)printf("-");puts(sum0);
		}
		
		fclose(fp);
	//system("pause");
return 0;
}