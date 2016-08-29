#include"stdio.h"
main()
{int a=1,b=1,c=1;
	for(a=1;a<=100;a++)
		for(b=1;b<=100;b++)
			for(c=1;c<=100;c++)
				if(a*a+b*b==c*c&&a<b)
					printf("%d^2+%d^2=%d^2\n",a,b,c);
}

