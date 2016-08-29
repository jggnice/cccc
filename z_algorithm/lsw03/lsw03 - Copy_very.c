#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void BigAdd(char c[],char a[],char b[])

{
 int i, an, bn, k;																	//an，bn是数组a，b的长度，k是较大的长度
 int temp1,temp2;
 int a_reverse[1000]={0}, b_reverse[1000]={0};
char c_reverse[1000];		
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
 int af[1000]={0},bf[1000]={0};
char  a_bac[1000],b_bac[1000],c_reverse[1000];

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
{int i=0,chn,sum=0,j=0;char *ch_bac;
	strcpy(ch_bac,ch);
	chn=strlen(ch_bac);//printf("\n[%d]\n",chn);
	if(ch_bac[chn-1]=='0')return 1;
	
	while(sum==0)
	{
		sum+=(ch_bac[i++]-'0');
	}
	i--;//printf("\n[%d]\n",i);
	while(ch[i])
	{
		ch[j++]=ch[i++];
	}ch[j]='\0';
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

int main(int argc, char* argv[])
{
 FILE *fp;
 char tep[1000],sum0[1000]="0";
 int n,signofnew=0,signofold=0;

//*********************checkblock***********************************
 //check parameters
 if(argc<2){printf("not enough parameters");system("pause");return 0;} 
 //check file
 if ((fp = fopen(argv[1], "rt")) == NULL)
   {printf("Can't open file.\n");system("pause");exit(EXIT_FAILURE);}
printf("\n%s",argv[0]);
printf("\n%s",argv[1]);
//*********************checkblock***********************************
fscanf(fp,"%d",&n);									//number of numbers		
	while(n>0)
	{
		fscanf(fp,"%s",tep);	n--;					//  signed number  tep
		signofnew=getstrnumber(tep);			//  unsigned number tep
		//*********************************************************
		if((signofnew)&&(signofold))
		{
			//两个负数相加
			//  unsigned number tep and sum0
			signofold=1;
			//printf("\nthe answer is \n");
			BigAdd(sum0,tep,sum0);//system("pause");
		}
		//*********************************************************		
		else if((signofnew)||(signofold))
		{
			//  unsigned number tep and sum0
			//  assume that signofold=0;
			signofold=0;
			if(comparestr(sum0,tep)>=0)
			{
				if(!signofnew)
				signofold=1;
				
				
				//printf("\nthe answer is \n");
				BigSub(sum0,sum0,tep);
				//system("pause");
				
				
			}
			else
			{
				if(signofnew)
				signofold=1;
				
				//printf("\nthe answer is \n");
				BigSub(sum0,tep,sum0);//system("pause");				
				
			}
		}
		//*********************************************************		
		else
		{
			//两个正数相加
			//  unsigned number tep and sum0
			signofold=0;
			//printf("\nthe answer is \n");
			BigAdd(sum0,tep,sum0);			
			//system("pause");
		}
	}
//**************************block***********************************
		printf("\nthe answer is\n");
		if(get_in_the_end(sum0)==1)printf("0");
		else
		{
			if(signofold==1)printf("-");puts(sum0);
		}
		
		fclose(fp);
	system("pause");
return 0;
}