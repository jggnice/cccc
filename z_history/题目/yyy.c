/*#include<iostream.h>
#include"stdio.h"
struct info
{int k;
char *s;
}t;
void f(struct info f)
{t.k=1997;
t.s="Borland";
}
void main()
{
	t.k=2000;
	t.s="inprise";
	f(t);
	printf(¡°%d,%s\n¡±,t .k, t.s);
}*/

#include"stdio.h"
main()
{/*
 int a=1;printf("%d,%d,%d\n",++a,++a,++a);/*

 /*
  int m=7,n=4;
float a=38.4,b=6.4,x;
x=m/2+n*a/b+1/2;
printf("%f\n",x);
int i=1,j=1,k=2; 
if((j++||k++)&& i++)
printf("%d,%d,%d\n",i,j,k);/*
int a=21,b=11;
printf("%d\n",--a+b,--b+a);

int a=7,b=9,t;
t=a*=a>b?a:b;
printf("%d",t);
int x=1,y=2,z=3,a;
a=z+=x>y?++x:++y;
printf("%d",a);


int a=011;
printf("%d\n",++a);
int x=1,y=0,a=0,b=0;
  switch(x)
  {
     case 1:
       switch(y)
       {
         case 0:a++;break;
         case 1:b++;break;
       }
     case 2:a++;b++;break;
     case 3:a++;b++;break;
   }
   printf("a=%d,b=%d\n",a,b);

int i,j,k,a=3,b=2;
i=(--a==b++)?--a:++b;
j=a++;k=b;
printf("i=%d,j=%d,k=%d\n",i,j,k);
double x;x=218.82631;
printf("%-6.2e\n",x);
int a,b;
b=(a=3*5,a*4,a*5); printf("%d",b);
int j,k;
for(j=0,k=-1;k=1;j++,k++)
printf("****\n");
int a=011;
printf("%d %#o\n",++a,++a);
char ch1,ch2;
int n1,n2;
  ch1=getchar();
  ch2=getchar();
  n1=ch1-'0';
  n2=n1*10+(ch2-'0');
  printf("%d\n",n2);
int a[4][4]={{1,2,-3,4},{0,-12,-13,14},{-21,23,0,-24},{-31,32,-33,0}};
  int i,j,s=0;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++)
    { if(a[i][j]<0)
        continue;
      if(a[i][j]==0)
        break;
      s+=a[i][j];
     }}
  printf("%d\n",s);


int p,a=5;  
if(p=a!=0)
printf("%d",p);  
else 
printf("%d\n",p+2); 

int i,m=0,n=0,k=0;  
for(i=9;i<=11;i++)  
switch(i%10){   
case 0:m++;n++;break;   
case 10:n++;break;   
default:k++;n++;}  
printf("%d %d %d\n",m,n,k);

int a=1,b=3,c=5;  
if(c=a+b) 
printf("yes\n");  
else printf("no\n");/**/
}