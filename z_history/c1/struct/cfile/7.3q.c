#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#define N 5
#define E 6
#define maxsize 50
typedef char vextype;/*顶点类型*/
typedef struct node{int adj;struct node *next;}edgenode;/*边表节点或孩子链节点类型*/
typedef struct {vextype vext;edgenode *link;}vextnode;/*邻接表类型或孩子链表类型*/
vextnode ga[N+1];/*顶点表*/
vextnode T[N+1];/*树或森林*/
char str1[N]="abcde";/*顶点信息*/
int edge[2*E]={1,3,1,2,5,4,5,3,5,2,5,1};/*边信息*/
int visited[N+1]={0};
void CREATADJLIST(vextnode ga[],char A[],int B[])
{/*建立顶点表*//*破坏 ga*/
/*ga 是顶点表， A 是顶点集合， B 是边集合*/
int i,j,k;
edgenode *s;/*新建节点*/
/*读入顶点*/printf("read vext: ");
for(i=1;i<=N;i++)
{
ga[i].vext=A[i-1];printf("%c ",A[i-1]);
ga[i].link=NULL;
}
/*读入边，建立邻接表*/printf("\nread edge: ");
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
int visit[N+1]={0};/*未破坏 int visited[N+1]*/
int Q[maxsize];/*队列*/
int front=-1,rear=-1;/*队头，队尾*/
edgenode *p,*q;
printf("%c ",ga[k].vext);/*访问出发点*/
visit[k]=1;/*标记*/
Q[++rear]=k;/*访问过的入队*/
while(rear!=front)/*判空*/
{
p=ga[Q[++front]].link;/*表头指针*/
while(p!=NULL)
{
if(!visit[p->adj])
{
printf("%c ",ga[p->adj].vext);
q=malloc(sizeof(edgenode));/*新建孩子链*/
q->adj=p->adj;/*复制*/
q->next=T[Q[front]].link;/*头插*/
T[Q[front]].link=q; /*头插*/
/*printf("(%d,%d)",Q[front],p->adj);*/
visit[p->adj]=1; /*标记*/
Q[++rear]=p->adj; /*访问过的入队*/
}p=p->next; /*下一个*/
}
}
}/*BFSL1*/
void BFSL(int k)
{
/*破坏 int visited[N+1]*/
int Q[maxsize];/*队列*/
int front=-1,rear=-1;/*队头，队尾*/
edgenode *p;
printf("%c ",ga[k].vext);/*访问出发点*/
visited[k]=1;/*标记*/
Q[++rear]=k;/*访问过的入队*/
while(rear!=front)/*判空*/
{
p=ga[Q[++front]].link;/*表头指针*/
while(p!=NULL)
{
if(!visited[p->adj])
{
printf("%c ",ga[p->adj].vext);
visited[p->adj]=1; /*标记*/
Q[++rear]=p->adj; /*访问过的入队*/
}p=p->next; /*下一个*/
}
}
}/*BFSL*/
int try_travel(void)
{ /*破坏 int visited[N+1]*/
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
{ /*破坏 int visited[N+1]*/
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
{ /*未破坏 int visited[N+1]*/
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
/*初始化森林*//*破坏 T[N+1]*/
T[0].link=NULL;
for(i=1;i<=N;i++)
{
T[i].vext=str1[i-1];
T[i].link=NULL;
}
/*建立邻接表*//*破坏 ga*/
printf("\ncreat adj list:\n");
CREATADJLIST(ga,str1,edge);
/*检查是否有根*//*破坏 int visited[N+1]*/
k=try_travel();
if(k)
{
printf("\nroot:%d\nBFSL(%d):",k,k);
/*为 T[0]添加树根信息*/
p=malloc(sizeof(edgenode));
p->adj=k;
p->next=T[0].link;
T[0].link=p;
BFSL1(k);
}
else {printf("\nno root:\n");TRAVEL();}
/*遍历孩子链表*/
printf("\ntravelchild:\n");travelchildlink();
getch();
for(i=1;i<=N;i++)
{ deletel(ga[i].link);
deletel(T[i].link);
}
deletel(T[0].link);
}