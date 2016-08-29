/*
 * lsw15.c
 *
 *  Created on: 2015年12月22日
 *      Author: qq
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void getname(char *ch)
{
	int i=0,j=0;
	while(ch[i++])
	{
		if(ch[i-1]=='\\')
		{
			j=0;
			ch[0]='\0';
		}

		else ch[j++]=ch[i-1];

	}
	ch[j]='\0';
}
int main(int argc,char* argv[])
{
	FILE *fp, *pic;
	int length, i, k = 0, flag1 = 0, flag2 = 0;

	char *str,*chf;
	char ch[4];
	char temp;
//*********************checkblock***********************************
//check parameters
	if(argc<2)
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
	chf=argv[1];
	getname(chf);
	strcat(chf,".jpg");
	pic = fopen(chf, "wb+");
	if (pic == NULL)
	{
		printf("cannot open infile\n");
		return 0;
	}
//*********************checkblock***********************************

	fseek(fp, 0L, SEEK_END);
	length = ftell(fp);
	char DECODE[128] =
	{
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1,	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, 62, -1, 63,
		52, 53, 54,	55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1,
		-1, 0 , 1 , 2,  3 , 4 ,	5 , 6 , 7 , 8 , 9 , 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23,	24, 25, -1, -1, -1, -1, 63,
		-1, 26, 27, 28, 29, 30, 31, 32, 33, 34,	35, 36, 37, 38, 39, 40,
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1
	};
	str = (char *)malloc(sizeof(char) * length);

	rewind(fp);
	fread(str, 1, length, fp);
	for(i = 0; i < length; i ++)
	{
		//k was 0 at first;
		//printf("\n__%c__",str[i]);
		temp = DECODE[(int)str[i]];
		//printf("\n__%d__",temp);

		if(temp >= 0)
			ch[k ++] = temp;
		else if(str[i] == '=')
		{
			//printf("\nend");
			if(k == 2) flag1 = 2;
			if(k == 3) flag2 = 3;
			ch[k ++] = '=';
		}
//**********processing***********************
		if(k == 4 && flag1 == 0 && flag2 == 0)
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
		if(k == 4 && flag1 == 0 && flag2 ==3)
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
		if(k == 4 && flag1 == 2 && flag2 ==3)
		{
			k = 0;
			ch[0] = ch[0] << 2;
			temp = ch[1];
			temp = temp >> 4;

			ch[0] += temp;

			fprintf(pic, "%c", ch[0]);
		}
	}
	printf("\ntime:%f second(s)",((double)clock()/CLOCKS_PER_SEC));
	return 0;
}
