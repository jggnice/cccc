/*/�ո�32�س�10
#include<stdio.h>
main()
{
	int n=0;
	char ch1,ch2;
	do
	{
		ch1=getchar();
		if(ch1!=' ')
		{
			do
			ch2=getchar();
			while(ch2!=' '&&ch2!=10);
			n++;
		}//��ǰͷ�пո����������
	}
		while(ch1!=10&&ch2!=10);
		printf("������Ϊ%d",n);
}

*//*
#include"stdio.h"
main()
{char c=32,d=0;int i=0;
while(c!=10)
{d=c;c=getchar();
if(d==32&&c!=32)i++;}
if(d!=32&&c!=32)
printf("%d",i);
else printf("%d",i-1);}

*/#include"stdio.h"
main()
{char c=32,d=0;int i=0;
while(c!=10)
{if(d==32&&c!=32)i++;d=c;c=getchar();}
printf("%d",i);}
