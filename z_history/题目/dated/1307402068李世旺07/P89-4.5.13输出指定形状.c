#include"stdio.h"
main()
{int n,i=0,j=0;
scanf("%d",&n);
for(i=1;i<=n;i++)
{	for(j=1;j<=n-i;j++)
		printf(" ");
    for(j=1;j<=i;j++)
		printf("*");
	printf("\n");
}

}