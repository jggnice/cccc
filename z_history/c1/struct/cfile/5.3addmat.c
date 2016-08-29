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
link *addmat(link *a,link *b)
{                                       /*新建chm链表*/
	link *p,                         /*变量：新建节点*/
    *qa,*qb,                       /*头链表的活动指针*/
    *q1,*q2,               /*十字链表一行上的活动指针*/
    *chm,                            /*结果矩阵头指针*/
    *cps[smax];                      /*批量处理头链表*/
		int i,                                 /*计数*/
        m1=a->ri,m2=a->cj,m4=m1;          /* 行数列数*/
		datatype x;              /*保存值域相加的结果*/
if((a->ri!=b->ri)||(a->cj!=b->cj))
return NULL; 
		if(m2>m4)m4=m2;
		chm=malloc(sizeof(link));             /*开辟*/
		chm->ri=m1;chm->cj=m2;
		cps[0]=chm;
		                                 /*头节点链表*/
for(i=1;i<=m4;i++)
    {   p=malloc(sizeof(link));
        p->ri=0;p->cj=0;
        p->next_col=p;p->next_row=p;
        cps[i]=p;cps[i-1]->uval.next=p; 
    }   cps[m4]->uval.next=chm;          /*空十字链表*/
    qa=a->uval.next;qb=b->uval.next;
while((qa!=a)&&(qb!=b))
{                                          /*same row*/
	q1=qa->next_col;q2=qb->next_col;
	while((q1!=qa)&&(q2!=qb)) /*结束后或有一个先走出*/
	{   if (q1->cj==q2->cj)                /*same one*/
		{     x=q1->uval.v+q2->uval.v;
		      if (x!=0)
			  {					  /*生成新节点并插入*/
				p=malloc(sizeof(link));
				p->ri=q1->ri;p->cj=q1->cj;
				p->uval.v=x;
				insertmat(chm,p);
			  }
		q1=q1->next_col;q2=q2->next_col;	  /*此处同步*/
		}
		else
		{     /*not one*/
			if(q1->cj<=q2->cj)
            {/*生成新节点,复制数据,插入*/;
				p=malloc(sizeof(link));
				p->ri=q1->ri;p->cj=q1->cj;
				p->uval.v=q1->uval.v;
				insertmat(chm,p);
			q1=q1->next_col;			  /*先行一步*/
			}
			else
			{/*生成新节点*/;
				p=malloc(sizeof(link));
				p->ri=q2->ri;p->cj=q2->cj;
				p->uval.v=q2->uval.v;
				insertmat(chm,p);
			q2=q2->next_col;	
			}			  /*先行一步*/
		}
	}
	while(q1!=qa)					  /*b先走，a跟上*/
	{/*循环新建节点，并复制、插入*/;
		p=malloc(sizeof(link));
		p->ri=q1->ri;p->cj=q1->cj;
		p->uval.v=q1->uval.v;
		insertmat(chm,p);
	q1=q1->next_col;
	}
	while(q2!=qb)					  /*b先走，a跟上*/
	{/*循环新建节点，并复制、插入*/;
		p=malloc(sizeof(link));
		p->ri=q2->ri;p->cj=q2->cj;
		p->uval.v=q2->uval.v;
		insertmat(chm,p);
	q2=q2->next_col;	
	}
	qa=qa->uval.next;qb=qb->uval.next;/*保证同步进行*/	
}
return chm;
}
