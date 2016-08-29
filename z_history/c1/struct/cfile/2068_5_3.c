#include"stdio.h"
#include"stdlib.h"
#define smax 30
typedef int datatype;
typedef struct hmnode
{		int ri,cj;							/*������*/
		struct hmnode *next_row,*next_col;	/*����ָ��*/
		union 
			{struct hmnode *next;			/*��ͷָ��*/
				datatype v;					/*ֵ*/
			}	uval;						/*ֵ��*/
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

		 /*��������,���ر�ͷָ��,�����ʽ scanf v1 v2 v3 ��m3��*/
link *CREATLINKMAT(void)
{link *p,*hm,*cps[smax];
		int i,											 /*����*/
		m1,m2,m3,							/*��������������� */
		m4,										/*m1��m2�ϴ�� */
		v1,v2;datatype v3;
											   /*���� m1 m2 m3 */
		printf("max[m,n]<=%d\ninput m n t for row column nonzero:",smax);
		scanf("%d%d%d",&m1,&m2,&m3);
		m4=m1;if(m2>m1)m4=m2;
		hm=malloc(sizeof(link));						  /*����*/
		hm->ri=m1;hm->cj=m2;
		cps[0]=hm;
								/*����ͷ�ڵ�ѭ��������ʮ������*/
for(i=1;i<=m4;i++)
	{	p=malloc(sizeof(link));
		p->ri=0;p->cj=0;
		p->next_col=p;p->next_row=p;
		cps[i]=p;cps[i-1]->uval.next=p; 
	}	cps[m4]->uval.next=hm;
											/*��Ԫ�����ʮ������*/
printf("input i j v for %d time(s)\n",m3);
	for(i=1;i<=m3;i++)
	{									  /*����һ����Ԫ��v1v2v3*/
		scanf("%d%d%d",&v1,&v2,&v3);
		p=malloc(sizeof(link));
		p->ri=v1;p->cj=v2;p->uval.v=v3;     /*�Ȱ��½ڵ����ݷź�*/ 
		insertmat(hm,p);								/*insert*/
	}
return hm;
}

												  /*�����������*/
void listmat(link *L)
{int i=0,/*�ϴ�������������ʼΪ0*/
j,/*��¼������*/
k,/*����0����*/
k1,/*����ѭ������*/
d;/*0����*/
link *p,/*Ԫ��ָ��*/
*q;/*ͷ�ڵ�ָ��*/
q=L->uval.next;									  /*qָ���һ��*/
for(k1=1;k1<=L->ri;k1++)   						 /*����ѭ������*/ 

{	i=0;/*�ظ���ʼ��*/
	p=q->next_col;									/*������һ��*/
						/*if(p==q)���У���Ӻ������0�����ظ�*/
	while(p!=q)
    {	j=p->cj;									/*��¼������*/
		d=j-i-1;	  								/*����0����*/
		i=j;							  		/*��¼�ϴε���*/
		for(k=1;k<=d;k++)printf("    0");				/*��ӡ0*/
		printf("%5d",p->uval.v);					/*��ӡ����*/
		p=p->next_col;								/*������һ��*/
	}

	for(k=1;k<=L->cj-i;k++)printf("    0");
	/*��ʱ(p==q)����¼i��ֵ��������油����0*/
	printf("\n");/*	listrow(L,q);*/
		q=q->uval.next;									/*��һ��*/
}
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
if((a->ri!=b->ri)||(a->cj!=b->cj))	 /**�ж��ܷ����**/
{printf("matrix size do not match!");return NULL;}
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
void del_i_j(link *L,int i,int j)
{	int ii,jj;							/*����*/
link *p0=L,*p1,*p2,/*��ı�ͷ�ڵ㣬��ڵ㣬��ǰ��*/
	*q0=L,*q1,*q2;
for(ii=1;ii<=i;ii++)
p0=p0->uval.next;
p1=p0;								/*�ҵ���ͷ�ڵ�*/
while((p1->next_col->cj!=j)&&(p1->next_col!=p0))
	p1=p1->next_col;
p2=p1->next_col;						/*�ҵ�ǰ��*/
p1->next_col=p2->next_col;				/*��Խ�ڵ�*/

for(jj=1;jj<=j;jj++)
q0=q0->uval.next;
q1=q0;								/*�ҵ���ͷ�ڵ�*/
while((q1->next_row->ri!=i)&&(q1->next_row!=q0)) 
	q1=q1->next_row;
q2=q1->next_row;						/*�ҵ�ǰ��*/
q1->next_row=q2->next_row;				/*��Խ�ڵ�*/
free(q2);								/*ɾ���ڵ�*/
}
void delone(link *L,link *L0)
{		link *p,*q;					
		/*����ɾ*/
		p=L->next_col;	    /*������һ��*/
		while(p!=L)
		{q=p->next_col;		/*������һ��*/
		free(p);
		p=q;
		}free(L);
	

}
void delmat(link *L)
{link *p,*q;
p=L->uval.next;/*��ָ���һ����ͷ*/
while(p!=L)			   /*����ʱ����*/
    {q=p->uval.next; /*ǰ��һ����ͷ*/
    delone(p,L);	/*ɾ��һ��ѭ������*/
    p=q;			   /*��һ����ͷ*/
    }free(L);				  /*����*/
}


/*������*/
main()
{	link *hm1,*hm2,*hm3;			/*����1,2,3*/
	int i,j;					 /*ɾ����λ��*/
hm1=CREATLINKMAT();printf("\nOK!\n");listmat(hm1);
hm2=CREATLINKMAT();printf("\nOK!\n");listmat(hm2);
hm3=addmat(hm1,hm2);					/*���*/
if(hm3)
	{	printf("\nOK!\n the sum is\n");
		listmat(hm3);
					/*���������ӣ���ʾ���*/
printf("input del i,j\n");		  /*ɾ����λ��*/
scanf("%d%d",&i,&j);del_i_j(hm3,i,j);	  /*ɾ��*/
listmat(hm3);
}							  /*��ʾ*/
delmat(hm1);delmat(hm2);delmat(hm3);	  /*ɾ��*/
getch(); 								  /*��ͣ*/
}
