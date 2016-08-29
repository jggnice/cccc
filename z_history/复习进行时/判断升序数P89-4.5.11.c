/*#include"stdio.h"
main()
{int x=100,a,b,c,i=0;
	while(x<1000)
	{a=x%10;b=(x/10)%10;c=(x/100)%10;
	if(a>b&&b>c)
	{printf("%d ",x);i++;if(i%9==0)printf("\n");}
	x++;}
}
*/



/*#include"stdio.h"
int is_rising(int a[],int x)
{int i,j,p;
	for(i=0;x>0;i++,p++){a[i]=x%10;x/=10;}
	for(;i>0;i--){if(a[i]<a[i-1])j++;}
    if(j>=p)p=0;else p=1;
return p;}
main()
{int a[30],x;
	scanf("%d",&x);if(is_rising(a,x)==0)printf("ÉıĞòÊı");else printf("²»ÊÇ");


}*/