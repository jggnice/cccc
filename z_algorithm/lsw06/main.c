#include <stdio.h>
#include <stdlib.h>
#include"lsw06.h"

int main(int argc, char** argv)
{

	FILE *fp1,*fp2;

//*********************checkblock***********************************
	if ((fp1 = fopen("input.txt", "rt")) == NULL)
	{
		printf("Can't open file.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen("out.txt", "at+")) == NULL)
	{
		printf("Can't open file.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}
//*********************checkblock***********************************

	link *p1;
	p1 = link_create(fp1);
	link_print(p1,fp2);
	printf("\nresult in file out.txt.\n");
	//********* clear *****************
	fclose(fp1);
	fclose(fp2);	
	return (EXIT_SUCCESS);
}