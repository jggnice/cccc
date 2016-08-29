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
link *addmat(link *a,link *b)
{                                       /*�½�chm����*/
	link *p,                         /*�������½��ڵ�*/
    *qa,*qb,                       /*ͷ����Ļָ��*/
    *q1,*q2,               /*ʮ������һ���ϵĻָ��*/
    *chm,                            /*�������ͷָ��*/
    *cps[smax];                      /*��������ͷ����*/
		int i,                                 /*����*/
        m1=a->ri,m2=a->cj,m4=m1;          /* ��������*/
		datatype x;              /*����ֵ����ӵĽ��*/
if((a->ri!=b->ri)||(a->cj!=b->cj))
return NULL; 
		if(m2>m4)m4=m2;
		chm=malloc(sizeof(link));             /*����*/
		chm->ri=m1;chm->cj=m2;
		cps[0]=chm;
		                                 /*ͷ�ڵ�����*/
for(i=1;i<=m4;i++)
    {   p=malloc(sizeof(link));
        p->ri=0;p->cj=0;
        p->next_col=p;p->next_row=p;
        cps[i]=p;cps[i-1]->uval.next=p; 
    }   cps[m4]->uval.next=chm;          /*��ʮ������*/
    qa=a->uval.next;qb=b->uval.next;
while((qa!=a)&&(qb!=b))
{                                          /*same row*/
	q1=qa->next_col;q2=qb->next_col;
	while((q1!=qa)&&(q2!=qb)) /*���������һ�����߳�*/
	{   if (q1->cj==q2->cj)                /*same one*/
		{     x=q1->uval.v+q2->uval.v;
		      if (x!=0)
			  {					  /*�����½ڵ㲢����*/
				p=malloc(sizeof(link));
				p->ri=q1->ri;p->cj=q1->cj;
				p->uval.v=x;
				insertmat(chm,p);
			  }
		q1=q1->next_col;q2=q2->next_col;	  /*�˴�ͬ��*/
		}
		else
		{     /*not one*/
			if(q1->cj<=q2->cj)
            {/*�����½ڵ�,��������,����*/;
				p=malloc(sizeof(link));
				p->ri=q1->ri;p->cj=q1->cj;
				p->uval.v=q1->uval.v;
				insertmat(chm,p);
			q1=q1->next_col;			  /*����һ��*/
			}
			else
			{/*�����½ڵ�*/;
				p=malloc(sizeof(link));
				p->ri=q2->ri;p->cj=q2->cj;
				p->uval.v=q2->uval.v;
				insertmat(chm,p);
			q2=q2->next_col;	
			}			  /*����һ��*/
		}
	}
	while(q1!=qa)					  /*b���ߣ�a����*/
	{/*ѭ���½��ڵ㣬�����ơ�����*/;
		p=malloc(sizeof(link));
		p->ri=q1->ri;p->cj=q1->cj;
		p->uval.v=q1->uval.v;
		insertmat(chm,p);
	q1=q1->next_col;
	}
	while(q2!=qb)					  /*b���ߣ�a����*/
	{/*ѭ���½��ڵ㣬�����ơ�����*/;
		p=malloc(sizeof(link));
		p->ri=q2->ri;p->cj=q2->cj;
		p->uval.v=q2->uval.v;
		insertmat(chm,p);
	q2=q2->next_col;	
	}
	qa=qa->uval.next;qb=qb->uval.next;/*��֤ͬ������*/	
}
return chm;
}
