#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lsw03.h"
void BigAdd(char c[],char a[],char b[])

{
 int i, an, bn, k;																	//an，bn是数组a，b的长度，k是较大的长度
 int temp1,temp2;
 int a_reverse[1200]={0}, b_reverse[1200]={0};
char c_reverse[1200];		
		an=strlen(a);//printf("\nan=%d\n",an);	
		bn=strlen(b);//printf("bn=%d\n",bn);
		k=an>bn?an:bn;
		for(i=0;i<an;i++)a_reverse[i]=a[an-i-1]-'0';								//将a数组反过来
		//for(i=an-1;i>=0;i--){printf("%d",a_reverse[i]);}printf("\n");
		for(i=0;i<bn;i++)b_reverse[i]=b[bn-i-1]-'0';								//将b数组反过来
		//for(i=bn-1;i>=0;i--){printf("%d",b_reverse[i]);}printf("\n");
		c[0]=0;
		for(i=0;i<k;i++)											//k是较大的长度;
		{
			temp1=(c[i]+a_reverse[i]+b_reverse[i])%10;//printf("[%d,",temp1);
			temp2=(c[i]+a_reverse[i]+b_reverse[i])/10;   //printf("%d]\n",temp2);
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
	//puts(c);
	//c完成返回

}
//************************************************************************************
void BigSub(char c[],char a[],char b[])

{	
 
 int i,an,bn,k;
 int af[1200]={0},bf[1200]={0};
char  a_bac[1200],b_bac[1200],c_reverse[1200];

strcpy(a_bac,a);//非常奇怪的是,b数组如果不进行备份的话,a的内容被篡改了
strcpy(b_bac,b);//非常奇怪的是,b数组如果不进行备份的话,b的内容被篡改了
 //怀疑下面两个语句对a,b发生篡改
an=strlen(a); //怀疑这个语句对a,b发生篡改						
bn=strlen(b); //怀疑这个语句对a,b发生篡改	
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
//正向字符串比较
 int an,bn;
 an=strlen(a);
 bn=strlen(b);
 if(strcmp(a,b)==0)  return 0;
 if(an>bn)  return 1;
 else if(an==bn)  return strcmp(a,b);
 else  return -1;
}
