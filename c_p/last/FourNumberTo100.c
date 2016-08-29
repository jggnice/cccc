#include"stdio.h"
#include<stdlib.h>
main()
{
	int a,b,c,d,count=0;
	FILE *fp;
	fp = fopen("count.txt","wt");
	for(a=1;a<=99;a++)
		for(b=a;b<99;b++)
			for(c=b;c<99;c++)
				if(100-a-b-c>=c){count++;fprintf(fp,"%d %d %d %d\n",a,b,c,100-a-b-c);}
fclose(fp);printf("%d",count);}