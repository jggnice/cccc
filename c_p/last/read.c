#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void getname(char *ch)
{int i=0,j=0;
	while(ch[i++])
	{
		if(ch[i-1]=='\\')
			j=0;
		ch[j++]=ch[i];

	}ch[i]='\0';
}

int main(int argc,char* argv[])
{
	FILE *fp,*fp2;
	char ch,*chf;
	fp = fopen(argv[1],"rt");
	
	chf=argv[1];
	getname(chf);
	strcat(chf,"mi");
	puts(chf);
	fp2 = fopen(chf,"wt");
	if (fp2 == NULL)
	{
		printf("cannot open infile\n");
		return 0;
	}
	if (fp == NULL)
	{
		printf("cannot open infile\n");
		return 0;
	}
	while(  (ch=fgetc(fp)) !=EOF)
	{putchar(ch);fputc(ch,fp2);}


	fclose(fp);fclose(fp2);
	system("pause");return 0;
}
