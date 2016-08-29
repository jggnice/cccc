#include"stdio.h"
main()
{int count[26]={0},i=0,j;char str[100];
gets(str);
while(str[i])
{if(64<str[i]&&str[i]<91)str[i]+=32;
count[str[i]-'a']++;i++;}

for(i=0;i<26;i++) {if(count[i]>0)printf("%d¸ö%c ",count[i],'a'+i);}

}