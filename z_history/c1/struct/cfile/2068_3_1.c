#include"stdio.h" 
#include"stdlib.h"
#define M 100
typedef char datatype; 
typedef struct
{ datatype V[M];int top0,top1;}seqstack;
/*两个栈共享向量空间*/
/*进栈*/
void push(seqstack *S,int i,datatype x)
{if(S->top0+1==S->top1){printf("overflow");}
else  { if(i==0){S->top0++;S->V[S->top0]=x;}
        if(i==1){S->top1--;S->V[S->top1]=x;}
      }
}
/*出栈*/
datatype pop(seqstack *S,int i)
{                     if(i==0)
          {if(S->top0<=-1){printf("\nstack0underflow\n");return NULL;}
          else {S->top0--;printf("\tpop top0 %c\t",S->V[(S->top0)+1]);return S->V[(S->top0)+1];}
          }         
                      if(i==1)
          {if(S->top1==M){printf("\nstack1underflow\n");return NULL;}
          else {S->top1++;printf("\tpop top1 %c\t",S->V[(S->top1)-1]);return S->V[(S->top1)-1];}
          }
}
/*取栈顶*/
datatype top(seqstack *S,int i)
{                     if(i==0)
          {if(S->top0<=-1){printf("\nstack0empty\n");return NULL;}
          else {printf("\tnow top0data  %c\t",S->V[(S->top0)]);return S->V[(S->top0)];}
          }         
                      if(i==1)
          {if(S->top1==M){printf("\nstack1empty\n");return NULL;}
          else {printf("\tnow top1data  %c\t",S->V[(S->top1)]);return S->V[(S->top1)];}
          }
}
void showstack(seqstack *S)
{    int r1=S->top0,r2=S->top1;
     printf("\tstack0:");
while(r1>=0){printf("%c ",S->V[r1]);r1--;} 
    
     printf("\tstack1:");
while(r2<M){printf("%c ",S->V[r2]);r2++;} 
     printf("\n");
}
main()
{int i=0,j=0;char str1[100],ch;
char str2[100];
seqstack *S=(seqstack *)malloc(sizeof(seqstack));/*开辟*/
S->top0=-1;S->top1=M;
printf("please push a string for stack0\n");gets(str1); 
printf("please push a string for stack1\n");gets(str2); 
while(str1[i]!='\0')
{push(S,0,str1[i]);i++;}
while(str2[j]!='\0')
{push(S,1,str2[j]);j++;}
printf(">>functios:\n1:pop(S,0)\t2:pop(S,1)\t3:top(S,0)\t4:top(S,1)\t5:showstacks\n$:exit\n");
while((ch=getchar())!='$')
	{
		switch(ch)
		{
		case '1':
			pop(S,0);
				break;
		case '2':
			pop(S,1);
				break;
		case '3':
			top(S,0);
				break;
		case '4':
			top(S,1);
				break;
		case '5':
			showstack(S);
				break;
		}
	}
getch();
free(S);
}
