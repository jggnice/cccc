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
	p->next_row=q->next_row;q->next_row=p;printf("OK%d! ",i);	
}

/*�����������ر�ͷָ��  ���룺��ʽ scanf v1 v2 v3 ��m3��*/
link *CREATLINKMAT(void)
{link *p,*q,*hm,*cps[smax];
		int i,/*����*/
		m1,m2,m3,/*��������������� */
		m4,/*m1��m2�ϴ�� */
		v1,v2;datatype v3;
		/*���� m1 m2 m3 */
		printf("input m n t");
		scanf("%d%d%d",&m1,&m2,&m3);
		m4=m1;if(m2>m1)m4=m2;
		hm=malloc(sizeof(link));/*����*/
		hm->ri=m1;hm->cj=m2;
		cps[0]=hm;
/*�ڵ�����*/
for(i=1;i<=m4;i++)
{p=malloc(sizeof(link));
p->ri=0;p->cj=0;p->next_col=p;p->next_row=p;cps[i]=p;cps[i-1]->uval.next=p; 
}cps[m4]->uval.next=hm;
/*��Ԫ��*/
printf("input i j v for %d time(s)\n",m3);
for(i=1;i<=m3;i++)
{/*����һ����Ԫ��v1v2v3*/
		scanf("%d%d%d",&v1,&v2,&v3);
		p=malloc(sizeof(link));
		p->ri=v1;p->cj=v2;p->uval.v=v3;

insertmat(hm,p,v1,v2,v3); 
///*�����i��*/
//q=cps[v1];
//while((q->next_col!=cps[v1])&&(q->next_col->cj<v2))
//	q=q->next_col;
//p->next_col=q->next_col;q->next_col=p;
///*�����j��*/
//q=cps[v2];
//while((q->next_row!=cps[v2])&&(q->next_row->ri<v1))
//	q=q->next_row;
//p->next_row=q->next_row;q->next_row=p;printf("OK%d! ",i);
}
return hm;
}

/*�����������*/
void listrow(link *L0,link *L1)
{int i=0,j,k,d;link *p;
p=L1->next_col;
if (p==L1)
	for(k=1;k<=L0->cj;k++)
		printf("    0");/*����*/

while(p!=L1)
{	j=p->cj;d=j-i-1;i=j;
	/*printf("-%d",d);*/
	if (d>0){for(k=1;k<=d;k++)printf("    0");}
	printf("%5d",p->uval.v);
	
	p=p->next_col;
}
}

void listmat(link *L)
{link *q;q=L->uval.next;
	do
	{
	listrow(L,q);printf("\n");
	q=q->uval.next;
	}while(q!=L);
}

//link *addmat(link *a,link *b)
//{/*�½�chm����*/
//	link *p,*qa,*qb,*q1,*q2,*chm,*cps[smax];
//		int i,/*����*/
//		m1=a->ri,m2=a->cj,m4=m1;/*�������� */
//		datatype x;
//		if(m2>m4)m4=m2;
//		chm=malloc(sizeof(link));/*����*/
//		chm->ri=m1;chm->cj=m2;
//		cps[0]=chm;
//		/*ͷ�ڵ�����*/
//for(i=1;i<=m4;i++)
//{p=malloc(sizeof(link));
//p->ri=0;p->cj=0;p->next_col=p;p->next_row=p;cps[i]=p;cps[i-1]->uval.next=p; 
//}cps[m4]->uval.next=hm;/*��ʮ������*/
//qa=a->uval.next;qb=b->uval.next;
//while((qa!=a)&&(qb!=b))
//{/*same row*/
//	q1=qa->next_col;q2=qb->next_col;
//	while((q1!=qa)&&(q2!=qb))
//	{/*same one*/
//		if (q1->cj==q2->cj)
//		{x=q1->uval.v+q2->uval.v;
//			if (x!=0){/*�����½ڵ�*/;}
//		q1=q1->next_col;q2=q2-next_col;
//		}
//		else
//		{
//			/*not one*/
//			{/*�����½ڵ�*/;}
//		q1=q1->next_col;q2=q2-next_col;	
//		}
//	qa=qa->uval.next;qb=qb->uval.next;	
//	}
//}
//
//}
/*������*/
main()
{link *hm;
hm=CREATLINKMAT();printf("\nOK!\n");
listmat(hm);
getch(); 
}
