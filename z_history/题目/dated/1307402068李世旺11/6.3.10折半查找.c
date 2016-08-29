

#define M 10 
#include"stdio.h"
 main() 
 {int a[M]={10,9,8,7,6,5,4,3,2,1};
float n; int l,m,h,f; 
l=0;h=M-1;f=0;  scanf("%f",&n);
 while(l<=h)  
 {m=(l+h)/2;
		if (n==a[m]) {f=1;break;}
    else if (n>a[m]) h=m-1;           
	else  l=m+1;     }

 if (f==1) printf("a[%d]\n",m); 
else printf("no %.3f",n); 
 }