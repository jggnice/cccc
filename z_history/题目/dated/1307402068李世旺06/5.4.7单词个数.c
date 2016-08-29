#include"stdio.h"
main()
{
char c=32,d=0;int i=0;

while(c!='\n')
{
	d=c;
	c=getchar();
if(d==32&&c!=32)
i++;}
 printf("%d",i);
}




/*do{
		while(c!=32)
		{c=getchar();}
i++;
		 while(c!=32)

		{c=getchar();}	
}while(c!='\n');
    printf("%d",i);
}
if (c!=32)*/