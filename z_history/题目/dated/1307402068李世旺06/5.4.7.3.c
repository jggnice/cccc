#include"stdio.h"
main()
{char c=32,d=0;int i=0;
while(c!=10)
{d=c;c=getchar();
if(d==32&&c!=32)i++;}
if(d!=32&&c!=32)printf("%d",i);
else printf("%d",i-1);}
