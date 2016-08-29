
#include"stdio.h"
void fun(int y,int *b,int * m)/*这里的*b可以替换成b[]*/
{	int i,j=0;
	*m=0;for(i=1;i<=y;i+=2)
	{if(y%i==0){b[(*m)++]=i;} }		
}
main()
{int b[100],i,y,n;
scanf("%d",&y);
fun(y,b,&n);

for(i=0;i<n;i++)printf("%d ",b[i]);
	printf("共有%d个 ",n);//i=getchar();i=getchar();
}