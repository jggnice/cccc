#include"time.h" 
#include"stdio.h"
#include"stdlib.h"
typedef struct cnode
{char ch;struct cnode * next;int freq;
}charnode;

charnode *creat(void)
{char ch1;
charnode  *L,*r,*p;
    L=(charnode *)malloc(sizeof(charnode));/*head*/
    r=L;
    printf("input string= ");
    ch1=getchar();
while(ch1!='\n')
   {p=(charnode *)malloc(sizeof(charnode));/*new node*/
    r->next=p;
    r=p;
    r->ch=ch1;
    r->freq=0;
    ch1=getchar();
   }
    r->next=NULL;
    return L;
}


charnode* locate(charnode *L,char cha)
{
  charnode *p,*q,*r1,*r2;
  p=L;q=L;
  while(p)
  { 
    if(p->next->ch!=cha)
    { p=p->next;
	/*没找到的情况*/
      if(!(p->next))
      {printf("\nnot found!");return NULL;}
    } 
    else 
    {/*找到的情况--删除结点*/
	 p->next->freq++;
     r1=p->next;
     p->next=r1->next;
     break;
    }
  }
/*search-找到的情况*/
 /*  L被置空的情况*/
  /*直接尾插*/
if(!(q->next))
{q->next=r1;
 r1->next=NULL;
 return q->next;
}
/*  L没有被置空*/
else
{
  while(q)
   if(q->next->freq>r1->freq)
    {q=q->next;
   /*每次比较均不成立的情况*/
   /*直接尾插*/
      if(!(q->next))
      {q->next=r1;
       r1->next=NULL;
       return q->next;
      }
    }
   
    else 
   {/*比较提前成立的情况*/
	/*插在r2前面*/ 
    r2=q->next;
    q->next=r1;
    r1->next=r2;
    return q->next;
   }
}  
}
void print(charnode *L)
{charnode *p;
   p=L->next;
    if(!p)
    {printf("\n empty list");return;}
    while(p)
    {printf("%c %d ",p->ch,p->freq);
     p=p->next;
    }printf("\t");
}


main()
{charnode *L;char ch1,ch;
    L=creat();print(L);
printf("\n1:find\t2:printL\t$:exit\n");
while((ch=getchar())!='$')
{
  switch(ch)
  {
   case '1':ch1=getchar();printf("input to find:");
            scanf("%c",&ch1);if(locate(L,ch1))print(L);break;
   case '2':print(L);
   case '\n':
   case '$':break;
   default:printf("illeagal input");
  }
}

    printf("\ntime:%f second(s)",((double)clock()/CLOCKS_PER_SEC));
   getch();free(L); 
}
