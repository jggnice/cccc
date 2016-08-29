#include"stdio.h"
#include"stdlib.h"

int main(int argc, char** argv)
{
	FILE *fp1;
int sum = 0;
int newone;
int count;
int i;
//*********************checkblock***********************************
//check parameters
	if (argc != 2)
	{
		printf("\nusage:\n a.exe input.txt\n");
		system("pause");
		return 0;
	}
	if ((fp1 = fopen(argv[1], "rt")) == NULL)
	{
		printf("Can't open file.\n");
		system("pause");
		exit (EXIT_FAILURE);
	}
//*********************checkblock***********************************
fscanf(fp1,"%d",&count);
for(i=0;i<count;i++)
{
	fscanf(fp1,"%d",&newone);
	sum += newone;
}
	fclose(fp1);
	printf("%d", sum);
}