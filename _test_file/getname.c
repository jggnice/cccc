#include<stdio.h>

void getname(char *ch)
{int i=0,j=0;
	while(ch[i++])
	{
		if(ch[i-1]=='\\'){j=0;ch[0]='\0';}
		
		else ch[j++]=ch[i-1];
		
	}ch[j]='\0';
//ע��ע��,������������,
//�������ʼ�������С�Ļ�,
//�Խϳ����ַ�����Ч.
}

int main()
{
	
	char String1[1000];
	scanf("%s",String1);
	getname(String1);
	puts(String1);
	return 0;
}