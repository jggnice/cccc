#include <stdio.h>
#include <stdlib.h>
#include"lsw07.h"
int main(int argc, char** argv)
{

	FILE *fp1;

//*********************checkblock***********************************
//check parameters
	if(argc<2)
	{
		printf("not enough parameters");
		system("pause");
		return 0;
	}
	if ((fp1 = fopen(argv[1], "rt")) == NULL)
	{
		printf("Can't open file.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}
	printf("%s\n%s",argv[0],argv[1]);
	
//*********************checkblock***********************************

	mytree * root;
	root = list_create(fp1);
	printf("\nresult = %d\n",tree_calculate(root));

	//********* clear *****************
	fclose(fp1);
	return (EXIT_SUCCESS);
}