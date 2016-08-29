#include"stdio.h"
/*程序功能】函数double atoe（char *s）的功能
将存储在s数组中用科学计数法表示的一个实数
的字符串形式转换成对应的double型实数，
并返回该值。
（科学计数法是指用e指数表示的一个实数。
例如，实数0.01345的科学记数法的字符串形式是"1.345e-2"。） 
若输入1.345e-2，则输出显示0.013450*/
#include"math.h"
double CtoF(char s[])   /*这里少了[]*/
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
	char s[20],m[20];double e;       /*这里定义e*/
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
