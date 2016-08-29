#include"stdio.h"
main()
{int max,min,r1=0,c1=0,i,j,r2=0,c2=0,a[4][4]/*={{2,1,3,4},{5,9,7,3},{2,8,6,2},{7,5,4,3}}*/;
for(i=0;i<4;i++)
for(j=0;j<4;j++)
scanf("%d",&a[i][j]);

max=a[0][0];min=a[0][0];
for(i=0;i<4;i++)
for(j=0;j<4;j++)
{if(a[i][j]>max){max=a[i][j];r1=i;c1=j;}
if(a[i][j]<min){min=a[i][j];r2=i;c2=j;}
}

printf("max=a[%d][%d]=%d\n",r1,c1,max);printf("min=a[%d][%d]=%d\n",r2,c2,min);
}