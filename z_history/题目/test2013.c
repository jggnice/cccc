#include"stdio.h"
/*�����ܡ�����double atoe��char *s���Ĺ���
���洢��s�������ÿ�ѧ��������ʾ��һ��ʵ��
���ַ�����ʽת���ɶ�Ӧ��double��ʵ����
�����ظ�ֵ��
����ѧ��������ָ��eָ����ʾ��һ��ʵ����
���磬ʵ��0.01345�Ŀ�ѧ���������ַ�����ʽ��"1.345e-2"���� 
������1.345e-2���������ʾ0.013450*/
#include"math.h"
double CtoF(char s[])   /*��������[]*/
{
	double val,power;
	int i=0,sign=1,start=0;
	
	if(s[0]=='+'||s[0]=='-') 
	{
	sign=(s[0]=='+')?1:-1;
		start=1;
	}
	for(val=0,i=start;s[i]&&s[i]!='.';i++)
		val=val*10+s[i]-'0';
	if(s[i++])
	for(power=1.0/10;s[i];i++)
		{
			val+=(s[i]-'0')*power;
			power/=10.0;
		}
	return val*sign;
}

main()
{
	char s[20],m[20];double e;       /*���ﶨ��e*/
	int i,j;
	double tail;
	gets(s);
	for (i=0;s[i]&&(s[i]!='e'||s[i]!='E');i++)
		m[i]=s[i];
	m[i]='\0';
	tail=CtoF(m);
	for(j=i+1,i=0;s[j];j++,i++)
		m[i]=s[j];
	m[i]='\0';
	e=CtoF(m);
	tail*=pow(10,e);
	printf("%lf\n",tail);
}
