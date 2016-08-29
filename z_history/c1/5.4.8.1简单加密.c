#include"stdio.h"
main()
{char c;
while(c!='\n')
	{c=getchar();
		if(c>='d'&&c<='z'||c>='D'&&c<='Z')c-=3;
		else c+=23;
	if(c!='\n'+23)putchar(c);
	}

}
