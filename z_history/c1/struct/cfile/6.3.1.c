#include"stdio.h"
#include"conio.h"
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
void in_order(bitree *t,FILE *fp)
{
	if(t)
	{
		in_order(t->lchild,fp);
		printf(" %c",t->data);fprintf(fp," %c",t->data);
		in_order(t->rchild,fp);
	}
}/*in_order*/

void pre_order(bitree *t,FILE *fp)
{   int top;
    bitree *s; 
	bitree *Q[maxsize];
	top=0;Q[top]=t;
	
do	
{   fprintf(fp," %c",Q[top]->data);
	printf(" %c",Q[top]->data);s=Q[top];top--;
    if(s->rchild){top++;Q[top]=s->rchild;}
    if(s->lchild){top++;Q[top]=s->lchild;}
}while(top>=0); 
}
int big(int a,int b)
{
    if(a>b)return a;
    return b;
}

int depth_of_tree(bitree *t)
{
	int h;
	if(!t)h=0;
	else {h=big(depth_of_tree(t->lchild),depth_of_tree(t->lchild))+1;}
	return h;
}


main()
{
	FILE *fp;char ch,preod[20],inod[20];bitree *t,*t_restore;int i=0;
	if((fp=fopen("mydata.txt","wt+"))==NULL)
	{printf("failed to open file !");getch();exit(1);}
	t=CREATREE();
	printf("pre_order:");
	pre_order(t,fp);
    printf("\n in_order:");
    fprintf(fp,"\n");
	in_order(t,fp);
    fprintf(fp,"\n");
    printf("\n depth is %d\n",depth_of_tree(t));

    rewind(fp); 
    while((ch=fgetc(fp))!='\n')
    {
        preod[i]=fgetc(fp);printf(" %c",preod[i]);i++;
    }
    i=0;
    while((ch=fgetc(fp))!='\n')
    {
        inod[i]=fgetc(fp);printf(" %c",inod[i]);i++;
    }


	fclose(fp);
	getch(); 
}

	

