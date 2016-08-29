#include"stdio.h"
main()
{char c;int i=0;
	for(c='A';c<='Z';c++)
	{printf("%c 八进制%o 十六进制%x 十进制%d  ",c,c,c,c);i++;if(i%2==0)printf("\n\n");}
}