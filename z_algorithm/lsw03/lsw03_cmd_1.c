
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* typedef struct
{
	
} Zen;
 */


int main(int argc, char* argv[])

{

 int i, an, bn, k;											//an��bn������a��b�ĳ��ȣ�k�ǽϴ�ĳ���
 int temp1,temp2;
 char *a, *b;								//�ַ�����a,b

 int a_reverse[1000]={0}, b_reverse[1000]={0}, c[1000]={0};		
 //int������c
 //a_reverse,b_reverse��a,b��������int�����顣
		if(argc<3){printf("not enough parameters");system("pause");return 0;}
		a=argv[1];
		b=argv[2];
		// scanf("%s", a);	
		// scanf("%s", b);	

		an=strlen(a);  printf("\nan=%d",an);									//an������a�ĳ���

		bn=strlen(b);	printf("\nbn=%d\n",bn);							//bn������b�ĳ���

		k=an>bn?an:bn;								//k�ǽϴ�ĳ���

		c[0]=0;

	//	f=0;

		for(i=0;i<an;i++)

   a_reverse[i]=a[an-i-1]-'0';								//��a���鷴����

		for(i=an-1;i>=0;i--)
		{printf("%d",a_reverse[i]);}printf("\n");

		for(i=0;i<bn;i++)

   b_reverse[i]=b[bn-i-1]-'0';								//��b���鷴����
			for(i=bn-1;i>=0;i--)
		{printf("%d",b_reverse[i]);}printf("\n");
  

		for(i=0;i<k;i++)											//k�ǽϴ�ĳ���;

		{

		temp1=(c[i]+a_reverse[i]+b_reverse[i])%10;printf("[%d,",temp1);

		temp2=(c[i]+a_reverse[i]+b_reverse[i])/10;	printf("%d]",temp2);
		c[i]=temp1;c[i+1]=temp2;

		}

		if(c[i]!=0) k++;                       					//if(��λ)k++

		printf("\n");
		for(i=k-1;i>=0;i--)
		{printf("%d",c[i]);}printf("\n");					//��ӡ 

		for(i=0;i<k;i++)

		{a_reverse[i]=0;b_reverse[i]=0;} 				//����

	system("pause");
return 0;
}