#include <stdio.h>
#include<stdlib.h>
int word_analyse(FILE *fp)
{
	char ch;
	int a = 0;
	char str[20];
	while(!(feof(fp)))
		{
			ch = fgetc(fp);
			putchar(ch);			
			//fscanf(fp,"%s",str);
			//puts(str);
		}
	return 0;
}
int main(int argc,char** argv)
{
	FILE *fp;
	if(argc != 2)
		{
			printf("useage: a.exe input.txt \n");
			system("pause");
			return 0;
		}
//check file
	fp = fopen(argv[1], "rt");
	if (fp == NULL)
		{
			printf("cannot open infile\n");
			return 0;
		}
	word_analyse(fp);
	return 0;
}