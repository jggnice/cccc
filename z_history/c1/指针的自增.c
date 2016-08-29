#include"stdio.h"
main()
{
	int a=9,*p=&a;

	printf("%d %d\n",(*p)++,(*p)++);
}
