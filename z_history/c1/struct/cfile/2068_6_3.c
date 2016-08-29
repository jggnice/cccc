#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#define maxsize 100
typedef char datatype;
typedef struct node 
{	datatype data;
	struct node *lchild,*rchild;
}bitree;
bitree *CREATREE(void)
{
	datatype ch;/*接收字符*/
	int front,rear;/*队头队尾*/
	bitree *root,*s;/*树根和新结点*/
	bitree *Q[maxsize];/*队列*/
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
{   int top;/*栈顶*/
    bitree *s;/*临时指针*/ 
	bitree *Q[maxsize];/*栈空间*/
	top=0;Q[top]=t;/*根节点进栈*/
	if(!t)return;
	
do	
{   fprintf(fp," %c",Q[top]->data);			/*访问节点*/
	printf(" %c",Q[top]->data);s=Q[top];top--;	/*出栈*/
    if(s->rchild){top++;Q[top]=s->rchild;}	/*右子进栈*/
    if(s->lchild){top++;Q[top]=s->lchild;}	/*左子进栈*/
}while(top>=0); 
}
int big(int a,int b)
{
    if(a>=b)return a;
    return b;
}/*比较大小*/

int depth_of_tree(bitree *t)
{
	int h;
	if(!t)h=0;
	else {h=big(depth_of_tree(t->lchild),depth_of_tree(t->rchild))+1;}
	return h;
}/*递归求高*/

bitree *restore(int start1,int start2,int len0,char *preod,char *inod)
{	bitree *p;			/*存放新建结点*/
	int loc,			/*目的节点下标*/
	len1,len2,		/*左右分支元素个数*/
	r1,r2,	  /*左分支前序中序起始下标*/
	s1,s2;	  /*右分支前序中序起始下标*/
	if(len0<=0)return NULL;
else{	p=malloc(sizeof(bitree));
	   p->data=preod[start1];/*printf("\nlist:");*/
	   loc=0;
	   while((inod[loc]!=p->data))
		{loc++;/*printf(" %c",inod[loc]);*/}
	   r1=start1+1;r2=start2;len1=loc-start2;
	   s1=start1+len1+1;s2=loc+1;len2=len0-len1-1;
	   p->lchild=restore(r1,r2,len1,preod,inod);
	   p->rchild=restore(s1,s2,len2,preod,inod);
        return p; 
}
}
void delete_tree(bitree *t)
{	if(!t)return;
    delete_tree(t->lchild);
	delete_tree(t->rchild);
	free(t);
}

main()
{
	FILE *fp;				/*文件指针（mydata.txt）*/
	char ch,				/*单个字符*/
	preod[20],				/*前序*/
	inod[20];				/*中序*/
	bitree *t,*t_restore;	/*生成树，恢复树*/
	int i=0;				/*计数*/
	
	if((fp=fopen("mydata.txt","wt+"))==NULL)
	{printf("failed to open file !");getch();exit(1);}

	printf("a tree:\n@ for NULL, # for end\n");
	t=CREATREE();
	if(!t)printf("empty tree!\n");				/*判空*/
	printf("pre_order:");
	pre_order(t,fp);fprintf(fp,"\n");			/*前序*/
    printf("\n in_order:");						/*中序*/
	in_order(t,fp);fprintf(fp,"\n");

    printf("\n depth is %d\n",depth_of_tree(t));/*深度*/
	
	printf("\ncheck preod[]:");		/*恢复和检查数组*/
    rewind(fp); 					  /*文件开始位置*/
    while((ch=fgetc(fp))!='\n')		/*恢复和检查数组*/
    {
        preod[i]=fgetc(fp);printf(" %c",preod[i]);i++;
    }
    i=0;printf("\ncheck inod[]:");
    while((ch=fgetc(fp))!='\n')		/*恢复和检查数组*/
    {
        inod[i]=fgetc(fp);printf(" %c",inod[i]);i++;
    }fclose(fp);

	t_restore=restore(0,0,i,preod,inod);	/*恢复*/

						/*检查时追加遍历序列到文件*/
	if((fp=fopen("mydata.txt","at+"))==NULL)
	{printf("failed to open file !");getch();exit(1);}
	printf("\nagain check pre_order:");		/*检查*/
	pre_order(t_restore,fp);fprintf(fp,"\n");
	printf("\nagain check in_order:");      /*检查*/
	in_order(t_restore,fp);fprintf(fp,"\n");
	fclose(fp);							/*检查完毕*/
	delete_tree(t);						  /*删除树*/
	delete_tree(t_restore);				  /*删除树*/
	getch(); 								/*暂停*/
}
