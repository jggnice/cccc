#include<stdio.h>

void getname(char *ch)
{int i=0,j=0;
	while(ch[i++])
	{
		if(ch[i-1]=='\\'){j=0;ch[0]='\0';}
		
		else ch[j++]=ch[i-1];
		
	}ch[j]='\0';
//注意注意,在主调函数中,
//如果不初始化数组大小的话,
//对较长的字符串无效.
}

int main()
{
	
	char String1[1000];
	scanf("%s",String1);
	getname(String1);
	puts(String1);
	return 0;
}