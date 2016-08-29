#include <stdio.h>
#include <stdlib.h>
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
    FILE *fp, *pic;
    int length, i, k = 0, mark1 = 0, mark2 = 0,res;
    char *str,*chf;
    char ch[4];
    char temp;
    fp = fopen(argv[1], "rt");
	chf=argv[1];
	getname(chf);
	strcat(chf,".out");
    pic = fopen(chf, "wb+");
	if (pic == NULL)
	{
		printf("cannot open infile\n");
		return 0;
	}
	if (fp == NULL)
	{
		printf("cannot open infile\n");
		return 0;
	}
    fseek(fp, 0L, SEEK_END);
    length = ftell(fp);
	res=length%4;
	
	if(res){printf("length error! remain %d letter(s)",res);system("pause");return 0;}
    str = (char *)malloc(sizeof(char) * length);
    rewind(fp);
    fread(str, 1, length, fp);
    for(i = 0; i < length; i ++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            ch[k ++] = str[i] - 'A';
        if(str[i] >= 'a' && str[i] <= 'z')
            ch[k ++] = str[i] - 'a' + 26;
        if(str[i] >= '0' && str[i] <= '9')
            ch[k ++] = str[i] - '0' + 52;
        if(str[i] == '+')
            ch[k ++] = 62;
        if(str[i] == '/')
            ch[k ++] = 63;
        if(str[i] == '=')
        {
            if(k == 2) mark1 = 2;
            if(k == 3) mark2 = 3;
            ch[k ++] = '=';
        }
        if(k == 4 && mark1 == 0 && mark2 == 0)
        {
			k = 0;
            ch[0] = ch[0] << 2;/*MUL 100B*/
            temp = ch[1];
			temp = temp >> 4;/*DIV 10000B*/

            ch[0] += temp;

            ch[1] = ch[1] << 4;/*MUL 10000B*/
            temp = ch[2];
			temp = temp >> 2;/*DIV 100B*/
            ch[1] += temp;

            ch[2] = ch[2] << 6;/*MUL 1000000B*/
            temp = ch[3];
            ch[2] += temp;
            fprintf(pic, "%c%c%c", ch[0], ch[1], ch[2]);
        }
        if(k == 4 && mark1 == 0 && mark2 ==3)
        {
			k = 0;
            ch[0] = ch[0] << 2;
            temp = ch[1];
			temp = temp >> 4;

            ch[0] += temp;

            ch[1] = ch[1] << 4;
            temp = ch[2];
			temp = temp >> 2;
            ch[1] += temp;

            fprintf(pic, "%c%c", ch[0], ch[1]);
        }
        if(k == 4 && mark1 == 2 && mark2 ==3)
        {
			k = 0;
           ch[0] = ch[0] << 2;
            temp = ch[1];
			temp = temp >> 4;

            ch[0] += temp;

            fprintf(pic, "%c", ch[0]);
        }
    }
	
   return 0;
}
