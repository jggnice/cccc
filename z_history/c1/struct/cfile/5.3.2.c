#include"stdio.h"
#include"stdlib.h"
#define smax 30
typedef int datatype;
typedef struct hmnode
{int ri,cj;/*行列域*/
struct hmnode *next_row,*next_col;/*竖直指针与水平指针*/
union 
	{struct hmnode *next;/*指针域*/
	datatype v;/*值域*/
	}uval;/*值域*/
}link;

/*函数建表，返回表头指针  输入：格式 scanf v1 v2 v3 共m3个*/
link *CREATLINKMAT(void)
{link *p,*q,*hm,*cps[smax];
		int i,/*计数*/
		m1,m2,m3,/*行数列数非零个数 */
		m4,/*m1，m2较大的 */
		v1,v2;datatype v3;
		/*输入 m1 m2 m3 */
		printf("max[m,n]<=%d\ninput m n t ",smax);
		scanf("%d%d%d",&m1,&m2,&m3);
		m4=m1;if(m2>m1)m4=m2;
		hm=malloc(sizeof(link));/*开辟*/
		hm->ri=m1;hm->cj=m2;
		cps[0]=hm;
/*节点链表*/
for(i=1;i<=m4;i++)
{p=malloc(sizeof(link));
p->ri=0;p->cj=0;p->next_col=p;p->next_row=p;cps[i]=p;cps[i-1]->uval.next=p; 
}cps[m4]->uval.next=hm;
/*三元组*/
printf("input i j v for %d time(s)\n",m3);
for(i=1;i<=m3;i++)
{/*输入一个三元组v1v2v3*/
		scanf("%d%d%d",&v1,&v2,&v3);
		p=malloc(sizeof(link));
		p->ri=v1;p->cj=v2;p->uval.v=v3;
/*插入第i行*/
q=cps[v1];
while((q->next_col!=cps[v1])&&(q->next_col->cj<v2))
	q=q->next_col;
p->next_col=q->next_col;q->next_col=p;
/*插入第j列*/
q=cps[v2];
while((q->next_row!=cps[v2])&&(q->next_row->ri<v1))
	q=q->next_row;
p->next_row=q->next_row;q->next_row=p;printf("OK%d! ",i);
}
return hm;
}
/*函数输出矩阵*/
void listmat(link *L)
{int i=0,j,k,d;link *p,*q;q=L->uval.next;
	do
	{i=0;/*two to one,initialization needed*/
	p=q->next_col;
/*与从后面计算0个数重复
     if (p==q)
//	    for(k=1;k<=L->cj;k++)
//		  printf("    0");/* printf("----0");空行*/
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
/*主函数*/
main()
{link *hm;
hm=CREATLINKMAT();printf("\nOK!\n");
listmat(hm);
getch(); 
}
