#include"stdio.h"
#include"string.h"
#include"math.h"
#include"conio.h"
ff(int a){auto b1=0;static c1=3;b1++;c1++;return(a+b1+c1);}
enum five{t=-100,y,u=0,r,l};
union  B  {int x;char c[8];};
struct MY {int x:3;float y:3;char z[20];union B un;} st[3];
typedef double INT64;
void main()
{int*p;char c[10]="\n\n\t\x32";register int i,sum;char a[7]="¿´×Å°É";
struct MY st[3]={{12,12,3},{14,14,6},{17,17,9}};st[0].un.x=66;
printf("%s %c\n",st[0].un.c,st[0].un.x);
printf("%d",st[0].x);printf("%d ",(st+1)->x);printf("%d\n",st[2].x);		
printf("%d ",st[0].y);printf("%d ",(st+1)->y);printf("%d ",st[2].y);
printf("%s\n",a);printf("%d\n",sizeof(INT64));
sum=0;for(i=0;i<1000;i++)sum+=i;
printf("%d\n",strlen(c));p="olympic";puts(p);
for(i=0;i<3;i++)printf("%d ",ff(2));

}
