#include"stdio.h"
#include"stdlib.h"
#define maxsize 100
typedef char datatype;
typedef struct node 
{	datatype data;
	int ltag,rtag;
	struct node *lchild,*rchild;
}bitree;
bitree *CREATREE(void)
{
	datatype ch;
	int front,rear;
	bitree *root,*s;
	bitree *Q[maxsize];
	
	root=NULL;
	front=1;rear=0;
	ch=getchar();
	while(ch!='#')
	{
		s=NULL;
		if(ch!='@')
		{
			s=malloc(sizeof(bitree));
			s->data=ch;s->lchild=NULL;s->rchild=NULL;
		}
		rear++;Q[rear]=s;
		if(rear==1)root=s;
		else
		{
			if(s&&Q[front])
				{   if(rear%2==0)Q[front]->lchild=s;
				    else	Q[front]->rchild=s;
                }
			if(rear%2==1)front++;
		}
		ch=getchar();
	}return root;
}/*CREATREE*/
void in_order(bitree *t)
{
	if(t)
	{
		in_order(t->lchild);
		printf("\t%c\n",t->data);
		in_order(t->rchild);
	}
}/*in_order*/

void in_thread(bitree *t)
{
	bitree *p;
	if(p!=NULL)
	{
		in_thread(p->lchild);
		if(p->lchild==NULL)p->ltag=1;
		if(p->rchild==NULL)p->rtag=1;
		if(pre!=NULL)
		{
			if(pre->rtag==1)pre->rchild=p;
			if(pre->ltag==1)pre->lchild=pre;
		}pre=p;
		in_thread(p->rchild);
	}
}/*in_thread*/

bitree *in_order_next(bitree *p)
{
	bitree *q;
	if(p->rtag==1)return(p->rchild);
	else 
	{
		q=p->rchild;
		while(q->ltag==0)q=q->lchild;
		return(q);
	}
}/*in_order_next*/

void travel_in_thead(bitree)
{
	if(p!=NULL)
	{
		while(p->ltag==0)p=p->lchild;
		do
		{
			printf("\t%d\n",p->data);
			p=in_order_next(p);
		}while(p!=NULL);
	}
}/*travel_in_thead*/

void insert_right(bitree *p,bitree *q)
{
	bitree *s;
	s=in_order_next(p);
	q->ltag=1;q->lchild=p;q->rtag=p->rtag;
	q->rchild=p->rchild;p->rtag=0;p->rchild=q;
	if((s!=NULL)&&(s->ltag==1))
		s->lchild=q;
}/*insert_right*/

main()
{
	bitree *t;
	t=CREATREE();
	in_order(t);in_thread(t);
}
