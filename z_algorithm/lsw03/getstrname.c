#include <stdio.h>
#include <stdlib.h>
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
int main()
{
	 char tep[1000];int f;
	 scanf("%s",tep);
	 f=getstrnumber(tep);
	 puts(tep);printf("flag=%d",f);
}
/* int comparestr(char *a,char *b)

{
//正向字符串比较
 int an,bn;
 an=strlen(a);
 bn=strlen(b);
 if(strcmp(a,b)==0)  return 0;
 if(an>bn)  return 1;
 else if(an==bn)  return strcmp(a,b);
 else  return -1;
} */