#include"math.h"
#include"stdio.h"
//���Լ������С������
long fmax(long m,long n)
{long r;
r=m%n;
//��mСʱ�������m���n��С
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