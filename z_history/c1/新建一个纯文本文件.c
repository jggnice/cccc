#include"stdio.h"//�½�һ�����ı��ļ��������Լ������ϵ�һ�仰���Լ�1000��������ÿ��5����ÿ��ռλ10�С�
#include"conio.h"
#include"stdlib.h"
void main()
{
	FILE * fp;char ch,str[20000];int a[1000],i,j,k=0;
	for(i=1;i<1000;i++)if(i>2&&i%2==0)a[i]=0;else a[i]=i;
	for(i=1;i<1000;i++)
		for(j=3;j<1000;j++)
			if(i%j==0&&i>j)
				a[i]=0;

	if((fp=fopen("D:\\my2.c","wt"))==NULL)
		{printf("no such thing");getch();exit(1);}

	puts("what do you want to say to me?");gets(str);fputs(str,fp);fprintf(fp,"\n");
	for(i=2;i<1000;i++)
		if(a[i]!=0){k++;fprintf(fp,"%10d",a[i]);if(k%5==0)fprintf(fp,"\n");}fclose(fp);

	if((fp=fopen("D:\\my2.c","rt"))==NULL)
		{printf("no such thing");getch();exit(1);}

	while((ch=fgetc(fp))!=EOF)putchar(ch);

	printf("\n");fclose(fp);
	fclose(fp);
}