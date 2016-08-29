#include"stdio.h"
#define m 3
#define n 4

main()
{int i,j,c,r=0,z=0,k,min,max,a[m][n]/*={{1,4,2,3},{3,6,8,9},{5,9,5,3}}*/;

for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);


for(i=0;i<m;i++)
{
	max=a[i][0];
	for(j=0;j<n;j++)
{if(a[i][j]>max){max=a[i][j];c=j;}}/*figure out the max collmon*/

min=a[0][c];for(k=0;k<m;k++)if(a[k][c]<min){min=a[k][c];r=k;}/*figure out the min one*/

if(min==max){z++;printf("a[%d][%d]=%d\n",r,c,min);}

}if(z==0)printf("马鞍点不存在");
}