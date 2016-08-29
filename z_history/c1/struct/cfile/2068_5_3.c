#include"stdio.h"
#include"stdlib.h"
#define smax 30
typedef int datatype;
typedef struct hmnode
{		int ri,cj;							/*行列域*/
		struct hmnode *next_row,*next_col;	/*列行指针*/
		union 
			{struct hmnode *next;			/*表头指针*/
				datatype v;					/*值*/
			}	uval;						/*值域*/
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

		 /*函数建表,返回表头指针,输入格式 scanf v1 v2 v3 共m3个*/
link *CREATLINKMAT(void)
{link *p,*hm,*cps[smax];
		int i,											 /*计数*/
		m1,m2,m3,							/*行数列数非零个数 */
		m4,										/*m1，m2较大的 */
		v1,v2;datatype v3;
											   /*输入 m1 m2 m3 */
		printf("max[m,n]<=%d\ninput m n t for row column nonzero:",smax);
		scanf("%d%d%d",&m1,&m2,&m3);
		m4=m1;if(m2>m1)m4=m2;
		hm=malloc(sizeof(link));						  /*开辟*/
		hm->ri=m1;hm->cj=m2;
		cps[0]=hm;
								/*建立头节点循环链表，空十字链表*/
for(i=1;i<=m4;i++)
	{	p=malloc(sizeof(link));
		p->ri=0;p->cj=0;
		p->next_col=p;p->next_row=p;
		cps[i]=p;cps[i-1]->uval.next=p; 
	}	cps[m4]->uval.next=hm;
											/*三元组插入十字链表*/
printf("input i j v for %d time(s)\n",m3);
	for(i=1;i<=m3;i++)
	{									  /*输入一个三元组v1v2v3*/
		scanf("%d%d%d",&v1,&v2,&v3);
		p=malloc(sizeof(link));
		p->ri=v1;p->cj=v2;p->uval.v=v3;     /*先把新节点数据放好*/ 
		insertmat(hm,p);								/*insert*/
	}
return hm;
}

												  /*函数输出矩阵*/
void listmat(link *L)
{int i=0,/*上次所在列数，初始为0*/
j,/*记录所在列*/
k,/*控制0个数*/
k1,/*控制循环行数*/
d;/*0个数*/
link *p,/*元素指针*/
*q;/*头节点指针*/
q=L->uval.next;									  /*q指向第一行*/
for(k1=1;k1<=L->ri;k1++)   						 /*控制循环行数*/ 

{	i=0;/*重复初始化*/
	p=q->next_col;									/*行中下一个*/
						/*if(p==q)空行，与从后面计算0个数重复*/
	while(p!=q)
    {	j=p->cj;									/*记录所在列*/
		d=j-i-1;	  								/*计算0个数*/
		i=j;							  		/*记录上次的列*/
		for(k=1;k<=d;k++)printf("    0");				/*打印0*/
		printf("%5d",p->uval.v);					/*打印数据*/
		p=p->next_col;								/*行中下一个*/
	}

	for(k=1;k<=L->cj-i;k++)printf("    0");
	/*此时(p==q)，记录i的值，计算后面补几个0*/
	printf("\n");/*	listrow(L,q);*/
		q=q->uval.next;									/*下一行*/
}
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
if((a->ri!=b->ri)||(a->cj!=b->cj))	 /**判断能否相加**/
{printf("matrix size do not match!");return NULL;}
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
void del_i_j(link *L,int i,int j)
{	int ii,jj;							/*计数*/
link *p0=L,*p1,*p2,/*活动的表头节点，活动节点，存前驱*/
	*q0=L,*q1,*q2;
for(ii=1;ii<=i;ii++)
p0=p0->uval.next;
p1=p0;								/*找到表头节点*/
while((p1->next_col->cj!=j)&&(p1->next_col!=p0))
	p1=p1->next_col;
p2=p1->next_col;						/*找到前驱*/
p1->next_col=p2->next_col;				/*跨越节点*/

for(jj=1;jj<=j;jj++)
q0=q0->uval.next;
q1=q0;								/*找到表头节点*/
while((q1->next_row->ri!=i)&&(q1->next_row!=q0)) 
	q1=q1->next_row;
q2=q1->next_row;						/*找到前驱*/
q1->next_row=q2->next_row;				/*跨越节点*/
free(q2);								/*删除节点*/
}
void delone(link *L,link *L0)
{		link *p,*q;					
		/*按行删*/
		p=L->next_col;	    /*行中下一个*/
		while(p!=L)
		{q=p->next_col;		/*行中下一个*/
		free(p);
		p=q;
		}free(L);
	

}
void delmat(link *L)
{link *p,*q;
p=L->uval.next;/*先指向第一个表头*/
while(p!=L)			   /*回来时结束*/
    {q=p->uval.next; /*前进一个表头*/
    delone(p,L);	/*删除一个循环链表*/
    p=q;			   /*下一个表头*/
    }free(L);				  /*拆桥*/
}


/*主函数*/
main()
{	link *hm1,*hm2,*hm3;			/*链表1,2,3*/
	int i,j;					 /*删除的位置*/
hm1=CREATLINKMAT();printf("\nOK!\n");listmat(hm1);
hm2=CREATLINKMAT();printf("\nOK!\n");listmat(hm2);
hm3=addmat(hm1,hm2);					/*相加*/
if(hm3)
	{	printf("\nOK!\n the sum is\n");
		listmat(hm3);
					/*如果正常相加，显示结果*/
printf("input del i,j\n");		  /*删除的位置*/
scanf("%d%d",&i,&j);del_i_j(hm3,i,j);	  /*删除*/
listmat(hm3);
}							  /*显示*/
delmat(hm1);delmat(hm2);delmat(hm3);	  /*删除*/
getch(); 								  /*暂停*/
}
