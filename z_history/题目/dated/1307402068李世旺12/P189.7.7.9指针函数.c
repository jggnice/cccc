#include"stdio.h"
int is_prime(int n)
{int p,i;
	for(i=2;i<n;i++)
{if(n%i==0)break;}
if(i==n)p=1;
else p=0;
return p;
}
int fun(int m,int *b)/*�����*b�����滻��b[]*/
{	int i,j=0;
	for(i=2;i<m;i++)
	{if(is_prime(i)==0){b[j++]=i;} }		
return j;}

main()
{int XX[100],i,k,m;
scanf("%d",&m);
k=fun(m,XX);
for(i=0;i<k;i++)
{printf("%3d ",XX[i]);if((i+1)%6==0)printf("\n");}printf("\n����%d�� ",k);}