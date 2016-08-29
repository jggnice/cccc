#include"stdio.h"
main()
{
	int i,s1,s2,d,k;
	for(i=1;i<=3000;i++)

{s1=0;s2=0;for(k=1;k<i;k++)
		{d=i%k;if(d==0)s1=s1+k;}
for(k=1;k<s1;k++)
		{d=s1%k;if(d==0)s2=s2+k;}
if(s2==i)printf("%d,%d\n",i,s1);
}
}