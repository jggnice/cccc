#include"stdio.h"
main()
{char c;int i=0;
	for(c='A';c<='Z';c++)
	{printf("%c �˽���%o ʮ������%x ʮ����%d  ",c,c,c,c);i++;if(i%2==0)printf("\n\n");}
}