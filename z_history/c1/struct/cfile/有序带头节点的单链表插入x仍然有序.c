/*有序带头节点的单链表插入x仍然有序*/
#include"stdio.h"
#include"stdlib.h"
typedef int datatype;
typedef struct node{datatype data;struct node *next;}linklist;
main()
{
void creat(linklist *h);//创建 
void list(linklist *h);//列出 
void insert(linklist *h,datatype x);//插入 
void del(linklist *h);//删除

 
linklist *head;datatype x;
head=(linklist *)malloc(sizeof(linklist));//开辟 
head->next=NULL;
printf("creat a list\n");
creat(head);
printf("list the linklist\n");
list(head);
printf("\ninputx= ");
scanf("%d",&x);
printf("list new linklist");
list(head);
printf("\ndelete the list");
del(head);
}

void creat(linklist *h)
{char numstr[8];
linklist *r,*new;
r=h;
printf("type @ to end\n");
printf("input node= ");
gets(numstr);
while(numstr[0]!='@')
    {new=(linklist *)malloc(sizeof(linklist));
    r->next=new;
    r=new;
    r->data=atoi(numstr);
    printf("input node= ");
    gets(numstr);
    }
    r->next=NULL;
}

void list(linklist *h)
	{int i=1;linklist *p;p=h->next;
	if(!p){printf("\n empty list");return;}
	do
	{printf("\n node number %d,value %d",i++,p->data);
	p=p->next;
	}while(p);
	}
void insert(linklist *h,datatype x)
{linklist *p,*q,*s;
s=(linklist *)malloc(sizeof(linklist));
s->data=x;
q=h;
p=q->next;
while(p&&p->data<x)
    {q=p;p=p->next;}
    s->next=p;
	q->next=s;//insert *s between *q & *p
}

void del(linklist *h)
{linklist *p=h,*q;
while(p)
	{q=p->next;
	free(p);
	p=q;
	}
}
