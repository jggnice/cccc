#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lsw03.h"
void BigAdd(char c[],char a[],char b[])

{
 int i, an, bn, k;																	//an��bn������a��b�ĳ��ȣ�k�ǽϴ�ĳ���
 int temp1,temp2;
 int a_reverse[1200]={0}, b_reverse[1200]={0};
char c_reverse[1200];		
		an=strlen(a);//printf("\nan=%d\n",an);	
		bn=strlen(b);//printf("bn=%d\n",bn);
		k=an>bn?an:bn;
		for(i=0;i<an;i++)a_reverse[i]=a[an-i-1]-'0';								//��a���鷴����
		//for(i=an-1;i>=0;i--){printf("%d",a_reverse[i]);}printf("\n");
		for(i=0;i<bn;i++)b_reverse[i]=b[bn-i-1]-'0';								//��b���鷴����
		//for(i=bn-1;i>=0;i--){printf("%d",b_reverse[i]);}printf("\n");
		c[0]=0;
		for(i=0;i<k;i++)											//k�ǽϴ�ĳ���;
		{
			temp1=(c[i]+a_reverse[i]+b_reverse[i])%10;//printf("[%d,",temp1);
			temp2=(c[i]+a_reverse[i]+b_reverse[i])/10;   //printf("%d]\n",temp2);
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
	//puts(c);
	//c��ɷ���

}
//************************************************************************************
void BigSub(char c[],char a[],char b[])

{	
 
 int i,an,bn,k;
 int af[1200]={0},bf[1200]={0};
char  a_bac[1200],b_bac[1200],c_reverse[1200];

strcpy(a_bac,a);//�ǳ���ֵ���,b������������б��ݵĻ�,a�����ݱ��۸���
strcpy(b_bac,b);//�ǳ���ֵ���,b������������б��ݵĻ�,b�����ݱ��۸���
 //����������������a,b�����۸�
an=strlen(a); //�����������a,b�����۸�						
bn=strlen(b); //�����������a,b�����۸�	
  k=an;c[0]=0;

  for(i=0;i<an;i++){af[i]=a_bac[an-i-1]-'0';}
  for(i=0;i<bn;i++){bf[i]=b_bac[bn-i-1]-'0';}

  for(i=0;i<k;i++)
  { if(af[i]>=bf[i])
	  c[i]=af[i]-bf[i];
    else 
	{c[i]=af[i]+10-bf[i];af[i+1]--;}
  }
  
// for(i=0;i<k;i++)
// printf("%d",c[i]);
  
  for(i=k-1;i>=0;i--)
    {
	//printf("*%d",c[i]);
	c_reverse[k-i-1]=c[i];
	//printf("%d",c_reverse[k-i-1]);
	}

//***************print_block
  for(i=0;i<k;i++)
  {
	c_reverse[i]+='0';//putchar(c_reverse[i]);
  }
  c_reverse[i]='\0';strcpy(c,c_reverse);
//printf("-->end of the function:");
//puts(c);
  
}
//****************************************************************************
int getstrnumber(char *ch)
{int i=0,flag=0;

	if(ch[i]=='-')flag=1;
	else if(ch[i]=='+')flag=0;
	else {return flag;}
	while(ch[i++])
	{
		ch[i-1]=ch[i];
	}
	return flag;
}
int get_in_the_end(char *ch)
{int i,chn,sum=0,j;

	i=0;
	//***************************
	while(ch[i++]);
	chn=i-1;	
	//printf("\nlength=[%d]\n",chn);

	//**************************
	i=0;
	while((sum==0)&&(i<chn))
	{
		sum+=(ch[i++]-'0');
	}
	i--;//printf("\nstart=[%d]\n",i);
	//**************************
	if(i==chn)return 1;// the string is totally zero
	if(i==0) return 0;// the string need not any change
	j=0;
	while(ch[i])
	{
		ch[j++]=ch[i++];
	}ch[j]='\0';
	//printf("\nfinallength=[%d]\n",j);
	return 0;
}
int comparestr(char *a,char *b)

{
//�����ַ����Ƚ�
 int an,bn;
 an=strlen(a);
 bn=strlen(b);
 if(strcmp(a,b)==0)  return 0;
 if(an>bn)  return 1;
 else if(an==bn)  return strcmp(a,b);
 else  return -1;
}
