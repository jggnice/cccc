/*
 * File:   main.c
 * Author: 旺
 *
 * Created on 2015年11月10日, 下午3:17
 */

#include <stdio.h>
#include <stdlib.h>
typedef int dtype;
typedef struct node{	dtype data;	struct node *lchild,*rchild;} bitree;

void print_sp(int start,int len,int*z)
{
	int ii;
	if(!len)return;
	printf("\n");
	for(ii=0;ii<len;ii++)
	{
		printf(" %d",z[start + ii]);
	}
	printf("\n");
}
bitree *restore(int len0,int start1,int start2,int *after,int *inod)
{
	bitree *p;
	int loc;
	int r1;
	int r2;
	int r3;
	int r4;
	int len1;
	int len2;

	if(len0 <= 0) return NULL;
	else
	{

		p=(bitree *)malloc(sizeof(bitree));
		p->data=after[start1 + len0 - 1];
		loc=0;
		while((inod[loc]!=p->data))
		{
			loc++;
		}
		r1=start1;
		r2=start2;
		len1=loc-start2;

		r3=start1+len1;
		r4=loc+1;
		len2=len0-len1-1;
		//print_sp(r1,len1,after);print_sp(r3,len2,after);
		//print_sp(r2,len1,inod);print_sp(r4,len2,inod);

		p->lchild=restore(len1,r1,r2,after,inod);
		p->rchild=restore(len2,r3,r4,after,inod);
		return p;
	}

}
void in_order(bitree *t)
{
	if(t)
	{
		in_order(t->lchild);
		printf(" %d",t->data);
		in_order(t->rchild);
	}
}/*in_order*/
void pre_order(bitree *t)
{
	if(t)
	{
		printf(" %d",t->data);
		pre_order(t->lchild);
		pre_order(t->rchild);
	}
}
void after_order(bitree *t)
{
	if(t)
	{
		after_order(t->lchild);
		after_order(t->rchild);
		printf(" %d",t->data);
	}
}

int main()
{
	dtype after[] = {105, 207, 89, 22, 28, 218, 216};
	dtype inod[] = {105, 89, 207, 216, 22, 218, 28};
	bitree *t_restore;	/*恢复树*/
	t_restore=restore(7,0,0,after,inod);
	printf("\n中序\n");
	in_order(t_restore);
	printf("\n后序\n");
	after_order(t_restore);
	printf("\n先序\n");
	pre_order(t_restore);
	return (EXIT_SUCCESS);
}
