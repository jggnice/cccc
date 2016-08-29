/*½âÃÜ*/#include"stdio.h"
main()
{char c;
while(c!='\n')
	{c=getchar();
		if(c>='d'&&c<='z'||c>='D'&&c<='Z')c-=3;
		else switch(c)
	{case 'a':c='x';break;
	case 'b':c='y';break;
	case 'c':c='z';break;
	case 'A':c='X';break;
	case 'B':c='Y';break;
	case 'C':c='Z';break;
	}
	putchar(c);
	}

}
