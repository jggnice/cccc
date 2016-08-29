#include "stdio.h"
#include <stdlib.h>
void main()
{
 FILE *in,*out;
 char ch;char ch1;
 
 if((in=fopen("file1.dat","r+"))==NULL)
 {
  printf("can,t open thie file!");
   exit(0);
 }
 if((out=fopen("file2.dat","w+"))==NULL)
 {
  printf("can,t open thie file!");
   exit(0);
 }

 while(!feof(in))
 {
     ch=fgetc(in);
     ch1=ch;
  fputc(ch1,out);//从infile中取入字符放到outfile文件中去
  
 }
 while(!feof(out))
 {
  
  ch=fgetc(out);
  
  putchar(ch);
  out++;
 }
 fclose(in);
 fclose(out);

}