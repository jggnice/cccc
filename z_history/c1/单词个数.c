#include"stdio.h"
main()
{char c=32,d=0;int i=0;//赋初值32（空格）
while(c!=10)
{d=c;c=getchar();
if(d==32&&c!=32)i++;}//以空格+非空格为一个单词的标志
if(d!=32&&c!=32)printf("%d",i);//回车（10）会作为非空格被getchar读入，故结尾分两种情况
else printf("%d",i-1);}//情况1：字母+回车即d!=32&&c!=32；情况2：空格+回车即d=32&&c!=32
//情况2满足一个单词的标志，故i-1