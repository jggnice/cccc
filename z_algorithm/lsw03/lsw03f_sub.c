#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void BigSub(char c[],char a[],char b[])

{	
 
 int i,an,bn,k;
 int af[1000]={0},bf[1000]={0};
char  b_bac[1000],c_reverse[1000];

  strcpy(b_bac,b);//非常奇怪的是,b数组如果不进行备份的话,b的内容凭空消失了
  
  an=strlen(a);printf("an=%d<-->in function:",an);puts(a);				//  unsigned number a
  bn=strlen(b);printf("bn=%d<-->in function:",bn);puts(b);				//  unsigned number b
  k=an;c[0]=0;

  for(i=0;i<an;i++){af[i]=a[an-i-1]-'0';}
  
  for(i=0;i<bn;i++){bf[i]=b_bac[bn-i-1]-'0';}
  
  //printf("__\n");
  
  for(i=0;i<k;i++)
  { if(af[i]>=bf[i])
	  c[i]=af[i]-bf[i];
    else 
	{c[i]=af[i]+10-bf[i];af[i+1]--;}
  }
//***************print_block********************
  
  for(i=k-1;i>=0;i--)
   {c_reverse[k-i-1]=c[i];}

//***************print_block********************
  for(i=0;i<k;i++)
  {
	c_reverse[i]+='0';//putchar(c_reverse[i]);
  }
  c_reverse[i]='\0';
  printf("-->end of function:");
  strcpy(c,c_reverse);
  puts(c);
  
}
int main()
{
	 char tep[1000],sum0[]="3";int f;
	 scanf("%s",tep);
	 f=getstrnumber(tep);
	 puts(tep);printf("flag=%d",f);
	 //BigSub(sum0,tep,sum0);system("pause");
	 BigSub(sum0,tep,sum0);system("pause");
	 
	 return 0;
}