#include"stdio.h"
#include"stdlib.h"
#define smax 30
typedef int datatype;
typedef struct hmnode
{int ri,cj;/*������*/
struct hmnode *next_row,*next_col;/*��ֱָ����ˮƽָ��*/
union 
	{struct hmnode *next;/*ָ����*/
	datatype v;/*ֵ��*/
	}uval;/*ֵ��*/
}link;

/*�����������ر�ͷָ��  ���룺��ʽ scanf v1 v2 v3 ��m3��*/
link *CREATLINKMAT(void)
{link *p,*q,*hm,*cps[smax];
		int i,/*����*/
		m1,m2,m3,/*��������������� */
		m4,/*m1��m2�ϴ�� */
		v1,v2;datatype v3;
		/*���� m1 m2 m3 */
		printf("max[m,n]<=%d\ninput m n t ",smax);
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
/*�����i��*/
q=cps[v1];
while((q->next_col!=cps[v1])&&(q->next_col->cj<v2))
	q=q->next_col;
p->next_col=q->next_col;q->next_col=p;
/*�����j��*/
q=cps[v2];
while((q->next_row!=cps[v2])&&(q->next_row->ri<v1))
	q=q->next_row;
p->next_row=q->next_row;q->next_row=p;printf("OK%d! ",i);
}
return hm;
}
/*�����������*/
void listmat(link *L)
{int i=0,j,k,d;link *p,*q;q=L->uval.next;
	do
	{i=0;/*two to one,initialization needed*/
	p=q->next_col;
/*��Ӻ������0�����ظ�
     if (p==q)
//	    for(k=1;k<=L->cj;k++)
//		  printf("    0");/* printf("----0");����*/
    while(p!=q)
    {	j=p->cj;d=j-i-1;
	   /*printf("-%d,%d",j,i);*/
		i=j;
	   for(k=1;k<=d;k++)printf("    0");/* printf("---+0");*/
	   printf("%5d",p->uval.v);
	
	p=p->next_col;
}

for(k=1;k<=L->cj-i;k++)printf("    0");
/*	listrow(L,q);*/
/* printf("\t%d\n",L->cj-i);*/
  printf("\n");
	q=q->uval.next;
	}while(q!=L);
}
/*������*/
main()
{link *hm;
hm=CREATLINKMAT();printf("\nOK!\n");
listmat(hm);
getch(); 
}
