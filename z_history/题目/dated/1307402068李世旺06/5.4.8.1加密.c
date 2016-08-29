/*¼ÓÃÜ*/#include"stdio.h"
main()
{char c;
while(c!='\n')
	{c=getchar();
		if(c>='a'&&c<='w'||c>='A'&&c<='W')c+=3;
		else switch(c)
	{case 'x':c='a';break;
	case 'y':c='b';break;
	case 'z':c='c';break;
	case 'X':c='A';break;
	case 'Y':c='B';break;
	case 'Z':c='C';break;
	}
	putchar(c);
	}

}
