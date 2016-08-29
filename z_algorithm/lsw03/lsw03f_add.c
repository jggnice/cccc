#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void BigAdd(char c[],char a[],char b[])

{
 int i, an, bn, k;																	//an，bn是数组a，b的长度，k是较大的长度
 int temp1,temp2;
 int a_reverse[1000]={0}, b_reverse[1000]={0};
char c_reverse[1000];		
		an=strlen(a);printf("\nan=%d\n",an);	
		bn=strlen(b);printf("bn=%d\n",bn);
		k=an>bn?an:bn;
		for(i=0;i<an;i++)a_reverse[i]=a[an-i-1]-'0';								//将a数组反过来
		for(i=an-1;i>=0;i--){printf("%d",a_reverse[i]);}printf("\n");
		for(i=0;i<bn;i++)b_reverse[i]=b[bn-i-1]-'0';								//将b数组反过来
		for(i=bn-1;i>=0;i--){printf("%d",b_reverse[i]);}printf("\n");
		c[0]=0;
		for(i=0;i<k;i++)											//k是较大的长度;
		{
			temp1=(c[i]+a_reverse[i]+b_reverse[i])%10;printf("[%d,",temp1);
			temp2=(c[i]+a_reverse[i]+b_reverse[i])/10;   printf("%d]\n",temp2);
			c[i]=temp1;c[i+1]=temp2;
		}	if(c[i]!=0) k++;                       					//if(进位)k++
//********************print_block*********************************
/* 		printf("\n");
		for(i=k-1;i>=0;i--)
		{printf("%d",c[i]);}printf("\n");					//打印  */
	//a是顺序char型数组.
	//b是顺序char型数组.
	//c是逆序char型数组.
	
	for(i=0;i<k;i++)
	c_reverse[i]=c[k-i-1]+'0';								//将c数组顺过来
	c_reverse[i]='\0';
   //c指向一片内存，逐项复制
	for(i=0;i<=k;i++)
	c[i]=c_reverse[i];
	puts(c);
	//c完成返回

}