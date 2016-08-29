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
	datatype ch;/*�����ַ�*/
	int front,rear;/*��ͷ��β*/
	bitree *root,*s;/*�������½��*/
	bitree *Q[maxsize];/*����*/
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
{   int top;/*ջ��*/
    bitree *s;/*��ʱָ��*/ 
	bitree *Q[maxsize];/*ջ�ռ�*/
	top=0;Q[top]=t;/*���ڵ��ջ*/
	if(!t)return;
	
do	
{   fprintf(fp," %c",Q[top]->data);			/*���ʽڵ�*/
	printf(" %c",Q[top]->data);s=Q[top];top--;	/*��ջ*/
    if(s->rchild){top++;Q[top]=s->rchild;}	/*���ӽ�ջ*/
    if(s->lchild){top++;Q[top]=s->lchild;}	/*���ӽ�ջ*/
}while(top>=0); 
}
int big(int a,int b)
{
    if(a>=b)return a;
    return b;
}/*�Ƚϴ�С*/

int depth_of_tree(bitree *t)
{
	int h;
	if(!t)h=0;
	else {h=big(depth_of_tree(t->lchild),depth_of_tree(t->rchild))+1;}
	return h;
}/*�ݹ����*/

bitree *restore(int start1,int start2,int len0,char *preod,char *inod)
{	bitree *p;			/*����½����*/
	int loc,			/*Ŀ�Ľڵ��±�*/
	len1,len2,		/*���ҷ�֧Ԫ�ظ���*/
	r1,r2,	  /*���֧ǰ��������ʼ�±�*/
	s1,s2;	  /*�ҷ�֧ǰ��������ʼ�±�*/
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
	FILE *fp;				/*�ļ�ָ�루mydata.txt��*/
	char ch,				/*�����ַ�*/
	preod[20],				/*ǰ��*/
	inod[20];				/*����*/
	bitree *t,*t_restore;	/*���������ָ���*/
	int i=0;				/*����*/
	
	if((fp=fopen("mydata.txt","wt+"))==NULL)
	{printf("failed to open file !");getch();exit(1);}

	printf("a tree:\n@ for NULL, # for end\n");
	t=CREATREE();
	if(!t)printf("empty tree!\n");				/*�п�*/
	printf("pre_order:");
	pre_order(t,fp);fprintf(fp,"\n");			/*ǰ��*/
    printf("\n in_order:");						/*����*/
	in_order(t,fp);fprintf(fp,"\n");

    printf("\n depth is %d\n",depth_of_tree(t));/*���*/
	
	printf("\ncheck preod[]:");		/*�ָ��ͼ������*/
    rewind(fp); 					  /*�ļ���ʼλ��*/
    while((ch=fgetc(fp))!='\n')		/*�ָ��ͼ������*/
    {
        preod[i]=fgetc(fp);printf(" %c",preod[i]);i++;
    }
    i=0;printf("\ncheck inod[]:");
    while((ch=fgetc(fp))!='\n')		/*�ָ��ͼ������*/
    {
        inod[i]=fgetc(fp);printf(" %c",inod[i]);i++;
    }fclose(fp);

	t_restore=restore(0,0,i,preod,inod);	/*�ָ�*/

						/*���ʱ׷�ӱ������е��ļ�*/
	if((fp=fopen("mydata.txt","at+"))==NULL)
	{printf("failed to open file !");getch();exit(1);}
	printf("\nagain check pre_order:");		/*���*/
	pre_order(t_restore,fp);fprintf(fp,"\n");
	printf("\nagain check in_order:");      /*���*/
	in_order(t_restore,fp);fprintf(fp,"\n");
	fclose(fp);							/*������*/
	delete_tree(t);						  /*ɾ����*/
	delete_tree(t_restore);				  /*ɾ����*/
	getch(); 								/*��ͣ*/
}
