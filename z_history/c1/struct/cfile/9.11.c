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
	/*û�ҵ������*/
      if(!(p->next))
      {printf("\nnot found!");return NULL;}
    } 
    else 
    {/*�ҵ������--ɾ�����*/
	 p->next->freq++;
     r1=p->next;
     p->next=r1->next;
     break;
    }
  }
/*search-�ҵ������*/
 /*  L���ÿյ����*/
  /*ֱ��β��*/
if(!(q->next))
{q->next=r1;
 r1->next=NULL;
 return q->next;
}
/*  Lû�б��ÿ�*/
else
{
  while(q)
   if(q->next->freq>r1->freq)
    {q=q->next;
   /*ÿ�αȽϾ������������*/
   /*ֱ��β��*/
      if(!(q->next))
      {q->next=r1;
       r1->next=NULL;
       return q->next;
      }
    }
   
    else 
   {/*�Ƚ���ǰ���������*/
	/*����r2ǰ��*/ 
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
