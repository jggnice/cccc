/*�Խ���С�ڵ���16�����õ���֪�������ƣ���Ч*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
main()
{int i,x1,y=0,k=0,z=0;
FILE * fp;char A[50];int N;
printf("�����½��ļ�������·��");gets(A);
if((fp=fopen(A,"w"))==NULL){printf("no such thing");getch();exit(1);}
printf("�����ƣ�");scanf("%d",&N);
for(i=0;i<=0xffff;i++)
{
x1=i;y=0;z=0;//!!!!!!!!!!!!!!
while(x1>0)
{y=0x10*y+x1%0x10;if(x1%0x10>=N)z++;x1/=0x10;}					//printf("((%d %d %d))\n",y,i,z);
if(y==i&&z==0){k++;printf("%6x",y);fprintf(fp,"%6x",y);if(k%5==0){printf("\n");fprintf(fp,"\n");}}
}
fclose(fp);getch();exit(1);
}