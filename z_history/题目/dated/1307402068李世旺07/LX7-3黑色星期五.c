#include"stdio.h"
main()
{int y,m,w;
	for(y=9;y<=30;y++)
		for(m=3;m<=14;m++)
		{w=y+(int)(y/4)+5-40+(int)(26*(m+1)/10)+12;
		w=w%7;if(w==5)
			{if(m==13)printf("%d,1,13\n",2000+y+1);
		else if(m==14)printf("%d,2,13\n",2000+y+1);
		else printf("%d,%d,13\n",2000+y,m);
			}
		}
}