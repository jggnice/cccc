#include"stdio.h"
#include"string.h"
#define N 5
#define M 8
void fun(char (*ss)[M])
{char *ps[N],*tp;int i,j;
for(i=0;i<N;i++)ps[i]=ss[i];
for(i=0;i<N-1;i++)
for(j=i+1;j<N;j++)
if(strlen(ps[i])<strlen(ps[j]))
{tp=ps[i];ps[i]=ps[j];ps[j]=tp;}
for(i=0;i<N;i++)puts(ps[i]);
}
main()
{char ch[N][M]={"red","green","blue","yellow","black"};fun(ch);
}