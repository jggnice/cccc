#include"stdio.h"
void main()
{int b,c,n,i=1,j=1;
printf("��һ��Ϊ���ĸ�����ÿ�����ÿո����");
	scanf("%d",&n);
	scanf("%d,",&c);
	while(i<=n-1)
		{scanf("%d,",&b);if(b<c) {c=b;j=i+1;}
		i++;
		}
	printf("\n\nmin is %d\nand it is the %d one\n\n",c,j);
}
  
