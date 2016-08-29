
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"lsw06.h"


void link_print(link * temp,FILE *fp)
{
	link * L = temp;
	if(!temp)
	{
		printf("NULL");
		return;
	}
	if (temp->next == NULL)
	{
		printf("NULL");
		return;
	}

	while(temp->next != L)
	{
		temp = temp->next;
		fprintf(fp,"%d ",temp->data);
	}
}
link * link_create(FILE *fp)
{
	int link_length;
	int cmd_length;
	int ii;
	link  *L,*tail,*temp;
	rewind(fp);
	fscanf(fp,"%d",&link_length);
	fscanf(fp,"%d",&cmd_length);
	if(!link_length)return NULL;
	L=(link *)malloc(sizeof(link));/*L= new head*/
	tail=L;
	for(ii = 0; ii<link_length; ii++)
	{
		temp = (link *)malloc(sizeof(link));/*temp = new node*/
		tail->next = temp;
		temp->pre = tail;
		tail=temp;
		tail->data=ii+1;
	}
	tail->next=L;
	L->pre=tail;
	link_move_file(L,fp,cmd_length);
	return L;
}
void link_move_file(link *L,FILE *fp, int cmd_length)
{
	char str[]="hkh";
	int aa,bb;
	int ii=0;
	//printf("\nSUCC%ld",ftell(fp));
	//system("pause");
	for(ii = 0; ii < cmd_length; ii++)
	{
		fscanf(fp,"%s",str);
		fscanf(fp,"%d",&aa);
		fscanf(fp,"%d",&bb);
		if(aa==bb)continue;
		//puts(str);
		//printf("\nSUCC%ld,%d,%d",ftell(fp),aa,bb);
		//system("pause");

		if(str[0] == 'L')
		{
			link_move_L(L,aa,bb);
		}
		if(str[0] == 'R')
		{
			link_move_R(L,aa,bb);
		}
	}
}
link* link_find(link *L,int data)
{
	if(!L)return NULL;
	link * temp=L->next;
	while((temp!=L)&&(temp->data!=data))temp=temp->next;
	return temp;
}
void link_move_R(link *L,int aa,int bb)
{
	link *a1,*a2,*temp;
	temp = link_find(L,aa);
	a1 = temp->pre;
	a2 = temp->next;
	a1->next = a2;
	a2->pre = a1;
	//**********************
	a1 = link_find(L,bb);
	a2 = a1->next;
	if(a2)
	{
		a1->next = temp;
		temp->pre = a1;
		a2->pre = temp;
		temp->next = a2;
	}/* else
	{
		a1->next = temp;
	temp->pre = a1;
	temp->next = NULL;
	} */
}
void link_move_L(link *L,int aa,int bb)
{
	link *a1,*a2,*temp;
	temp = link_find(L,aa);
	a1 = temp->pre;
	a2 = temp->next;
	a1->next = a2;
	a2->pre = a1;
	//**********************
	a2 = link_find(L,bb);
	a1 = a2->pre;
	a1->next = temp;
	temp->pre = a1;
	a2->pre = temp;
	temp->next = a2;
}