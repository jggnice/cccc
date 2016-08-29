
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* typedef struct
{
	
} Zen;
 */


int main(int argc, char* argv[])

{
 FILE *fp;
 int i, an, bn, k;								//an，bn是数组a，b的长度，k是较大的长度
 int temp1,temp2;
 char a[100], b[100];				//	字符数组a,b,有时是 *a，*b；
 int a_reverse[1000]={0}, b_reverse[1000]={0}, c[1000]={0};		 
 if(argc<2){printf("not enough parameters");system("pause");return 0;} 
 if ((fp = fopen(argv[1], "rt")) == NULL)
   {
      printf("Can't open file.\n");system("pause");
      exit(EXIT_FAILURE);
   }

		printf("%s\n",argv[0]);
		printf("%s\n",argv[1]);
	/*	i=0;
	 	while((ch=fgetc(fp))!='\n')
		{
			a[i++]=ch;
		}a[i]='\0';
		i=0;
		while((ch=fgetc(fp))!='\n')
		{
			b[i++]=ch;
		}b[i]='\0';
 */
	fscanf(fp,"%s",a);fscanf(fp,"%s",b);
	printf("%s\n",a);	
	printf("%s\n",b);	

		an=strlen(a);printf("\nan=%d",an);									//an是数组a的长度

		bn=strlen(b);printf("\nbn=%d\n",bn);							//bn是数组b的长度

		k=an>bn?an:bn;								//k是较大的长度

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
		fclose(fp);
	system("pause");
return 0;
}