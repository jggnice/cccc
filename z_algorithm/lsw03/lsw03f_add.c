#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void BigAdd(char c[],char a[],char b[])

{
 int i, an, bn, k;																	//an��bn������a��b�ĳ��ȣ�k�ǽϴ�ĳ���
 int temp1,temp2;
 int a_reverse[1000]={0}, b_reverse[1000]={0};
char c_reverse[1000];		
		an=strlen(a);printf("\nan=%d\n",an);	
		bn=strlen(b);printf("bn=%d\n",bn);
		k=an>bn?an:bn;
		for(i=0;i<an;i++)a_reverse[i]=a[an-i-1]-'0';								//��a���鷴����
		for(i=an-1;i>=0;i--){printf("%d",a_reverse[i]);}printf("\n");
		for(i=0;i<bn;i++)b_reverse[i]=b[bn-i-1]-'0';								//��b���鷴����
		for(i=bn-1;i>=0;i--){printf("%d",b_reverse[i]);}printf("\n");
		c[0]=0;
		for(i=0;i<k;i++)											//k�ǽϴ�ĳ���;
		{
			temp1=(c[i]+a_reverse[i]+b_reverse[i])%10;printf("[%d,",temp1);
			temp2=(c[i]+a_reverse[i]+b_reverse[i])/10;   printf("%d]\n",temp2);
			c[i]=temp1;c[i+1]=temp2;
		}	if(c[i]!=0) k++;                       					//if(��λ)k++
//********************print_block*********************************
/* 		printf("\n");
		for(i=k-1;i>=0;i--)
		{printf("%d",c[i]);}printf("\n");					//��ӡ  */
	//a��˳��char������.
	//b��˳��char������.
	//c������char������.
	
	for(i=0;i<k;i++)
	c_reverse[i]=c[k-i-1]+'0';								//��c����˳����
	c_reverse[i]='\0';
   //cָ��һƬ�ڴ棬�����
	for(i=0;i<=k;i++)
	c[i]=c_reverse[i];
	puts(c);
	//c��ɷ���

}