#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	FILE *into,*fp;
	char ch;
	if (argc != 2)
	{
		printf("\nusage:\n a.exe input.txt\n");
		system("pause");
		return 0;
	}
	if ((fp = fopen(argv[1], "rt")) == NULL)
	{
		printf("Can't open file.\n");
		exit(EXIT_FAILURE);
	}
	if ((into = fopen("ans.txt", "wt")) == NULL)
	{
		printf("Can't open file.\n");
		exit(EXIT_FAILURE);
	}
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch>='A'&&ch<='Z')
		{
			fputc(ch+32,into);
		}
		else if(ch>='a'&&ch<='z')
			fputc(ch,into);
		else
			fputc(' ',into);
	}
	fclose(fp);
	fclose(into);
	return 0;
}