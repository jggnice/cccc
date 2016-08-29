/* 
 * File:   reverse_line.c
 * Author: 旺
 *
 * Created on October 3, 2015, 4:40 PM
 题记:
	在一个PDF文档中复制得到 词序逆序 的单词串
	为此写一个程序将其反过来
	如果每行都只有一个单词的话,
	相当于什么都没有做.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD_COUNT 100
#define WORD_LENGTH 400
/*
 *reverseLine char *testString,FILE *file
 */
void getname(char *ch)
{int i=0,j=0;
	while(ch[i++])
	{
		if(ch[i-1]=='\\'){j=0;ch[0]='\0';}
		
		else ch[j++]=ch[i-1];
		
	}ch[j]='\0';
}
void reverseLine(char * testString,FILE *file) 
{
 
    int i=0, j=0, k=0;
    
    char builder[WORD_COUNT][WORD_LENGTH];
	//下面的条件控制: 换行符不参与;在含有单词的句子中,还可以改进使得标点符号不参与
	//因为标点符号或者换行符都可能紧紧地跟在单词后面.
    while((testString[k++]!='\n')&&(testString[k-1]!='\0'))
    {
        if(testString[k-1]!=' ')
            builder[i][j++]=testString[k-1];
        else 
            {builder[i][j]='\0';i++;j=0;}
    
    }
    {builder[i][j]='\0';}
    for(k=i;k>=0;k--)
    {
       
        //fprintf(file,"%d ",k);
        fprintf(file,"%s ",(builder[k]));
       
        
    } fprintf(file,"\n");

    
}

int main(int argc,char** argv)
{
    FILE * pic, * sourse;
    
    char name[]="output.txt";
    char testString1[WORD_LENGTH]=" dream  a  have  I  and confident am I";
    

   if ((sourse = fopen(argv[1], "rt+")) == NULL)
   {printf("Can't open file.\n");system("pause");exit(EXIT_FAILURE);}
  

    if ((pic = fopen(name, "wt+")) == NULL)
   {printf("Can't open file.\n");system("pause");exit(EXIT_FAILURE);}

    
    while(fgets(testString1,WORD_LENGTH,sourse))
    {
    reverseLine(testString1,pic);
    }

return (EXIT_SUCCESS);
}
