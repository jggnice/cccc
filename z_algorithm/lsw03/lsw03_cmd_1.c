
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* typedef struct
{
	
} Zen;
 */


int main(int argc, char* argv[])

{

 int i, an, bn, k;											//an，bn是数组a，b的长度，k是较大的长度
 int temp1,temp2;
 char *a, *b;								//字符数组a,b

 int a_reverse[1000]={0}, b_reverse[1000]={0}, c[1000]={0};		
 //int型数组c
 //a_reverse,b_reverse是a,b反过来的int型数组。
		if(argc<3){printf("not enough parameters");system("pause");return 0;}
		a=argv[1];
		b=argv[2];
		// scanf("%s", a);	
		// scanf("%s", b);	

		an=strlen(a);  printf("\nan=%d",an);									//an是数组a的长度

		bn=strlen(b);	printf("\nbn=%d\n",bn);							//bn是数组b的长度

		k=an>bn?an:bn;								//k是较大的长度

		c[0]=0;

	//	f=0;

		for(i=0;i<an;i++)

   a_reverse[i]=a[an-i-1]-'0';								//将a数组反过来

		for(i=an-1;i>=0;i--)
		{printf("%d",a_reverse[i]);}printf("\n");

		for(i=0;i<bn;i++)

   b_reverse[i]=b[bn-i-1]-'0';								//将b数组反过来
			for(i=bn-1;i>=0;i--)
		{printf("%d",b_reverse[i]);}printf("\n");
  

		for(i=0;i<k;i++)											//k是较大的长度;

		{

		temp1=(c[i]+a_reverse[i]+b_reverse[i])%10;printf("[%d,",temp1);

		temp2=(c[i]+a_reverse[i]+b_reverse[i])/10;	printf("%d]",temp2);
		c[i]=temp1;c[i+1]=temp2;

		}

		if(c[i]!=0) k++;                       					//if(进位)k++

		printf("\n");
		for(i=k-1;i>=0;i--)
		{printf("%d",c[i]);}printf("\n");					//打印 

		for(i=0;i<k;i++)

		{a_reverse[i]=0;b_reverse[i]=0;} 				//归零

	system("pause");
return 0;
}