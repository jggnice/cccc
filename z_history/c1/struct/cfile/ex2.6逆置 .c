#include"stdio.h"//ÄæÖÃ 
typedef char datatype;
typedef struct node
{datatype data;struct node *next;}linklist;
void invert(linklist *L)
{linklist *p,*r1,*r2;int i=0,j=0,k=0;
		r1=L;p=L;
	while(p->next!=NULL){p=p->next;i++;}
		r2=p;
	for(j=0;j<i;j++)
	{r2->next=r1->next;r1->next=r2;r1=r1->next;p=L;
	for(k=0;k<i;k++)p=p->next;
	r2=p;
	}
}
