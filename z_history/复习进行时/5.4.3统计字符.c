#include"stdio.h"
main()
{ int i=0,j=0,k=0;char c;
do
	{c=getchar();
	if(c>='a'&&c<='z'||c>='A'&&c<='Z')
		i++;
	else {if(c>='0'&&c<='9')
		j++;
	else k++;}}
	while(c!='\n');
	printf("%d个英文字母%d个数字%d个其他字符",i,j,k-1);
}