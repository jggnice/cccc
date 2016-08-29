#include"stdio.h"
#include"stdlib.h"
#define smax 30
typedef int datatype;
typedef struct hmnode
{int ri,cj;/*行列域*/
struct hmnode *next_row,*next_col;/*列行指针*/
union 
	{struct hmnode *next;/*指针域*/
	datatype v;/*值域*/
	}uval;/*值域*/
}link;
void insertmat(link *hm,link *p)
{
	link *q,*q1;int i;
	q=hm;
	for(i=1;i<=p->ri;i++)q=q->uval.next;
	q1=q;
	while((q->next_col!=q1)&&(q->next_col->cj<p->cj))
	q=q->next_col;
	p->next_col=q->next_col;q->next_col=p;
	q=hm;
	for(i=1;i<=p->cj;i++)q=q->uval.next;
	q1=q;
	while((q->next_row!=q1)&&(q->next_row->ri<p->ri))
	q=q->next_row;
	p->next_row=q->next_row;q->next_row=p;	
}
void delone(link *L)
{		link *p,*q;int flag=0;
		if(L->cj>L->ri)flag=1;
	if(flag==0)
	{	p=L->next_row;
		while(p!=L)
		{q=p->next_row;
		free(p);
		p=q;
		}free(L);
	}
	else
	{		p=L->next_col;
		while(p!=L)
		{q=p->next_col;
		free(p);
		p=q;
		}free(L);
	}
}
void delmat(link *L)
{link *p,*q;
p=L->uval.next;
while(p!=L)
    {q=p->uval.next;
    delone(p);
    p=q;
    }free(L);
}
void del_i_j(link *L,int i,int j)
{	int ii,jj;link *p0=L,*p1,*p2,*q0=L,*q1,*q2;
for(ii=1;ii<=i;ii++)
p0=p0->uval.next;
p1=p0;
while((p1->next_col->cj!=j)&&(p1->next_col!=p0))
	p1=p1->next_col;
p2=p1->next_col;
p1->next_col=p2->next_col;

for(jj=1;jj<=j;jj++)
q0=q0->uval.next;
q1=q0;
while((q1->next_row->ri!=i)&&(q1->next_row!=q0)) 
	q1=q1->next_row;
q2=q1->next_row;
q1->next_row=q2->next_row;
free(q2);
}
