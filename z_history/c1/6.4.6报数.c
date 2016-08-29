#include"stdio.h"
main()
{int a[10]={1,1,1,1,1,1,1,1,1,1},i=0,sum=0,j=10;
while(j>0)
{sum+=a[i];
			if(sum%3==0&&a[i]!=0){printf("%d ",i+1);a[i]=0;j--;}
		i++;i=i%10;
		}
}