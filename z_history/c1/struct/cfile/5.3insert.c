#include"stdio.h"
#include"stdlib.h"
#define smax 30
typedef int datatype;
typedef struct hmnode
{int ri,cj;/*������*/
struct hmnode *next_row,*next_col;/*����ָ��*/
union 
	{struct hmnode *next;/*ָ����*/
	datatype v;/*ֵ��*/
	}uval;/*ֵ��*/
}link;
void insertmat(link *hm,link *p,int v1,int v2,int v3)
{
	link *q=hm,*q1;int i;
	for(i=1;i<=v1;i++)q=q->uval.next;
	q1=q;
	while((q->next_col!=q1)&&(q->next_col->cj<v2))
		q=q->next_col;
	p->next_col=q->next_col;q->next_col=p;
	q=hm;
	for(i=1;i<=v2;i++)q=q->uval.next;
	q1=q;
	while((q->next_row!=q1)&&(q->next_row->ri<v1))
	q=q->next_row;
	p->next_row=q->next_row;q->next_row=p;	
}