#include"stdio.h"
main()
{int i,j,a[4][5]/*={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8}}*/,b[4]={0},max,min,m=0,n=0,t;
	for(i=0;i<4;i++)
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);
			

for(i=0;i<4;i++)
for(j=0;j<5;j++)b[i]+=a[i][j];

max=b[0];min=b[0];
for(i=0;i<4;i++)
{if(b[i]<max){max=b[i];m=i;};if(b[i]>min){min=b[i];n=i;}}
		printf("最大行");for(j=0;j<5;j++){printf(" %d",a[m][j]);}
		printf("最小行");for(j=0;j<5;j++){printf(" %d",a[n][j]);}

		for(j=0;j<5;j++){t=a[m][j];a[m][j]=a[n][j];a[n][j]=t;}//printf(" %d",m);printf(" %d",n);

printf("\n");
for(i=0;i<4;i++)
{for(j=0;j<5;j++)printf(" %d",a[i][j]);
printf("\n");}



}