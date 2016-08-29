#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#define N 5
#define E 6
#define maxsize 50
typedef char vextype;/*��������*/
typedef struct node{int adj;struct node *next;}edgenode;/*�߱�ڵ�������ڵ�����*/
typedef struct {vextype vext;edgenode *link;}vextnode;/*�ڽӱ����ͻ�����������*/
vextnode ga[N+1];/*�����*/
vextnode T[N+1];/*����ɭ��*/
char str1[N]="abcde";/*������Ϣ*/
int edge[2*E]={1,3,1,2,5,4,5,3,5,2,5,1};/*����Ϣ*/
int visited[N+1]={0};
void CREATADJLIST(vextnode ga[],char A[],int B[])
{/*���������*//*�ƻ� ga*/
/*ga �Ƕ���� A �Ƕ��㼯�ϣ� B �Ǳ߼���*/
int i,j,k;
edgenode *s;/*�½��ڵ�*/
/*���붥��*/printf("read vext: ");
for(i=1;i<=N;i++)
{
ga[i].vext=A[i-1];printf("%c ",A[i-1]);
ga[i].link=NULL;
}
/*����ߣ������ڽӱ�*/printf("\nread edge: ");
for(k=0;k<E;k++)
{
i=B[2*k];j=B[2*k+1];printf("(%d,%d)",i,j);
s=malloc(sizeof(edgenode));
s->adj=j;
s->next=ga[i].link;
ga[i].link=s;
}
}/*CREATADJKLIST*/
void BFSL1(int k)
{
int visit[N+1]={0};/*δ�ƻ� int visited[N+1]*/
int Q[maxsize];/*����*/
int front=-1,rear=-1;/*��ͷ����β*/
edgenode *p,*q;
printf("%c ",ga[k].vext);/*���ʳ�����*/
visit[k]=1;/*���*/
Q[++rear]=k;/*���ʹ������*/
while(rear!=front)/*�п�*/
{
p=ga[Q[++front]].link;/*��ͷָ��*/
while(p!=NULL)
{
if(!visit[p->adj])
{
printf("%c ",ga[p->adj].vext);
q=malloc(sizeof(edgenode));/*�½�������*/
q->adj=p->adj;/*����*/
q->next=T[Q[front]].link;/*ͷ��*/
T[Q[front]].link=q; /*ͷ��*/
/*printf("(%d,%d)",Q[front],p->adj);*/
visit[p->adj]=1; /*���*/
Q[++rear]=p->adj; /*���ʹ������*/
}p=p->next; /*��һ��*/
}
}
}/*BFSL1*/
void BFSL(int k)
{
/*�ƻ� int visited[N+1]*/
int Q[maxsize];/*����*/
int front=-1,rear=-1;/*��ͷ����β*/
edgenode *p;
printf("%c ",ga[k].vext);/*���ʳ�����*/
visited[k]=1;/*���*/
Q[++rear]=k;/*���ʹ������*/
while(rear!=front)/*�п�*/
{
p=ga[Q[++front]].link;/*��ͷָ��*/
while(p!=NULL)
{
if(!visited[p->adj])
{
printf("%c ",ga[p->adj].vext);
visited[p->adj]=1; /*���*/
Q[++rear]=p->adj; /*���ʹ������*/
}p=p->next; /*��һ��*/
}
}
}/*BFSL*/
int try_travel(void)
{ /*�ƻ� int visited[N+1]*/
int i,j,k,sum;
for(i=1;i<=N;i++)
{
for(k=1;k<=N;k++)visited[k]=0;
sum=0;
printf("\nBFSL(%d):",i);BFSL(i);
for(j=1;j<=N;j++)
sum+=visited[j];
if(sum==N)
return i;
}
return 0;
}
void TRAVEL(void)
{ /*�ƻ� int visited[N+1]*/
int k;
int i;edgenode *p;
for(k=1;k<=N;k++)visited[k]=0;
for(i=1;i<=N;i++)
{if(!visited[i])
{
p=malloc(sizeof(edgenode));
p->adj=i;
p->next=T[0].link;
T[0].link=p;
BFSL(i);printf("tree_end\n");}
}
}/*TRAVEL*/
void travelchildlink()
{ /*δ�ƻ� int visited[N+1]*/
int i;int childvisit[N+1]={0};
edgenode *p=T[0].link;
while(p)
{
printf("Tree_root: %c;",T[p->adj].vext);
p=p->next;
}printf("\n");
for(i=1;i<=N;i++)
{p=T[i].link;
/*if(!childvisit[i])*/
printf("%c :",T[i].vext);
while(p!=NULL)
{
if(!childvisit[i])printf("(%c,%c) ",T[i].vext,T[p->adj].vext);
childvisit[p->adj]=1;
p=p->next;
}printf("\n");
}
}
void deletel(edgenode *L)
{edgenode *p,*q;
p=L;
while(p)
{q=p->next;
free(p);
p=q;
}
}
void main()
{int i,k;edgenode *p;
/*��ʼ��ɭ��*//*�ƻ� T[N+1]*/
T[0].link=NULL;
for(i=1;i<=N;i++)
{
T[i].vext=str1[i-1];
T[i].link=NULL;
}
/*�����ڽӱ�*//*�ƻ� ga*/
printf("\ncreat adj list:\n");
CREATADJLIST(ga,str1,edge);
/*����Ƿ��и�*//*�ƻ� int visited[N+1]*/
k=try_travel();
if(k)
{
printf("\nroot:%d\nBFSL(%d):",k,k);
/*Ϊ T[0]���������Ϣ*/
p=malloc(sizeof(edgenode));
p->adj=k;
p->next=T[0].link;
T[0].link=p;
BFSL1(k);
}
else {printf("\nno root:\n");TRAVEL();}
/*������������*/
printf("\ntravelchild:\n");travelchildlink();
getch();
for(i=1;i<=N;i++)
{ deletel(ga[i].link);
deletel(T[i].link);
}
deletel(T[0].link);
}