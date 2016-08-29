#include"math.h"
#include"stdio.h"
//最大公约数与最小公倍数
long fmax(long m,long n)
{long r;
r=m%n;
//当m小时，下面的m变大，n变小
while(r!=0)
{m=n;n=r;r=m%n;}
return n;
}
int fmin(int m,int n)
{return m*n/fmax(m,n);
}
main()
{long m,n;
scanf("%d%d",&m,&n);
printf("fmax=%d\nfmin=%d",fmax(m,n),fmin(m,n));
}