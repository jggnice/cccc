#include"stdio.h"
main()
{int a=1,b=1,i;
printf("1,1");
for(i=2;i<20;i+=2)
{a=a+b;printf(",%d",a);
b=a+b;printf(",%d",b);
}

}