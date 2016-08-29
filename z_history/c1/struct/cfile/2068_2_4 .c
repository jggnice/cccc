#include"stdio.h"/*单链表变三个循环链表 */
#include"stdlib.h"
typedef struct cnode
{char ch;
struct cnode * next;
}charnode;

charnode *creat(void)
{char ch1;
charnode  *L,*r,*p;
    L=(charnode *)malloc(sizeof(charnode));/*L= new head*/
    r=L;
    printf("input string= ");
    ch1=getchar();
while(ch1!='\n')
    {p=(charnode *)malloc(sizeof(charnode));/*p = new node*/
    r->next=p;r=p;r->ch=ch1;
    ch1=getchar();
    }
    r->next=NULL;return L;
}


charnode *creat_1(void)
    {charnode *L;
    L=(charnode *)malloc(sizeof(charnode));
    L->next=L;return L;
    }


void print(charnode *L)

{charnode *p;p=L->next;
    if(!p)  {printf("\n empty list");return;}
    while(p)
      {printf("%c ",p->ch);p=p->next;
    }
}

void print1(charnode *L)
{charnode *p;p=L->next;
    if(!p){printf("\n empty list");return;}
    while(p!=L)
    {printf("%c ",p->ch);
    p=p->next;
    }
    }


void sort(charnode *L,charnode *A,charnode *B,charnode *C)
{charnode *ra=A,*rb=B,*rc=C;
while(L->next!=NULL)
{   
    if(('a'<=L->next->ch&&L->next->ch<='z')||('A'<=L->next->ch&&L->next->ch<='Z'))
    {ra->next=L->next;ra=ra->next;L->next=L->next->next;}
    else if(('0'<=L->next->ch)&&(L->next->ch<='9'))
    {rb->next=L->next;rb=rb->next;L->next=L->next->next;}
    else 
    {rc->next=L->next;rc=rc->next;L->next=L->next->next;}
}ra->next=A;rb->next=B;rc->next=C;
}
void delete1(charnode *L)
{charnode *p,*q;
p=L->next;
while(p!=L)
    {q=p->next;
    free(p);
    p=q;
    }free(L);
}


main()
{charnode *L,*A,*B,*C;
    L=creat();
    A=creat_1();B=creat_1();C=creat_1();
    print(L); printf("\nL finished\n" );
    sort(L,A,B,C); printf("\nsort finished\n");
    printf("\nA  finished\n" );print1(A); 
     printf("\nB  finished\n" );print1(B); 
     printf("\nC finished\n" );print1(C); 
	
 delete1(A);delete1(B);delete1(C);free(L); 
   getch();
}
