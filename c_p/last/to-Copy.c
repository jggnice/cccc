#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
/*int tochar(int  cha)
{
  if(cha >= 0 && cha <= 25)
            cha=cha+'A';
  else if(cha>=26 && cha <= 51)
            cha =cha - 26 +'a';
  else if(cha >= 52 && cha <= 61)
            cha = cha - 52 + '0';
  else if(cha == 62)
            cha = '+';
  else if(cha == 63)
            cha = '/';
		return cha;
}
*/
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
	char tochar[64]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    long length;register int i=0;
    unsigned char *str;char *chf;
    unsigned char ch[3],ch4[4];
    fp = fopen(argv[1], "rb");
	chf=argv[1];
	getname(chf);
	strcat(chf,".txt");
    pic = fopen(chf, "wt+");
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
    str = (unsigned char *)malloc(sizeof(unsigned char) * length);/*数组str[]*/
    rewind(fp);    
	fread(str, 1, length, fp);/*挨个读出*/
    while(length>0)
{
	
	if(length > 2)
   {	
    ch[0]=str[i++];
	ch[1]=str[i++];
	ch[2]=str[i++];
	ch4[0]= ch[0]>>2;
	ch4[1]= ((ch[0]&3)<<4)|(ch[1]>>4);/*确定前边是0才左移*/
	ch4[2]= ((ch[1]&0xF)<<2)|(ch[2]>>6);	/*确定前边是0才左移*/
	ch4[3]= ch[2]&63;
/*not successful
ch4[0]=ch[0]>>2;
ch4[1]=(ch[0]<<6)>>2+(ch[1]>>4);
ch4[2]=(ch[1]<<4)>>2+(ch[2]>>6);
ch4[3]=(ch[2]<<2)>>2;*/
	ch4[0]=tochar[ch4[0]];
	ch4[1]=tochar[ch4[1]]; 
	ch4[2]=tochar[ch4[2]]; 	
	ch4[3]=tochar[ch4[3]]; 
	

   fprintf(pic, "%c%c%c%c", (ch4[0]), (ch4[1]), (ch4[2]),(ch4[3]));
   }
    if(length==2)
   {		
	ch[0]=str[i++];
	ch[1]=str[i++];
	ch4[0]= ch[0]>>2;
	ch4[1]= ((ch[0]&3)<<4)|(ch[1]>>4);/*确定前边是0才左移*/
	ch4[2]= ((ch[1]&0xF)<<2);	/*确定前边是0才左移*/

            fprintf(pic, "%c%c%c%c",tochar[ch4[0]], tochar[ch4[1]], tochar[ch4[2]],'=');
        }
    if(length==1)
   {ch[0]=str[i++];
	ch4[0]= ch[0]>>2;
	ch4[1]= ((ch[0]&3)<<4);/*确定前边是0才左移*/
		
            fprintf(pic, "%c%c%c%c",tochar[ch4[0]], tochar[ch4[1]], '=','=');
    }
	length-=3;
}
	fclose(fp);fclose(pic);

	printf("\ntime:%f second(s)",((double)clock()/CLOCKS_PER_SEC));
   return 0;
}
