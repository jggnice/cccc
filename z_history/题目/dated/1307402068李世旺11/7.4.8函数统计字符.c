#include"stdio.h"
#include"string.h"
void fun(char s[])
{int i,num=0,ch=0,sp=0,ot=0;
for(i=0;s[i];i++)
	{if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
		ch++;
	else if(s[i]>='0'&&s[i]<='9')
		num++;
	else if (s[i]==32)sp++;
	else ot++;}
printf("char:%d,number:%d,space:%d,other:%d\n",ch,num,sp,ot);}
main()
{char s1[81];
gets(s1);
fun(s1);
}