typedef char datatype;
typedef struct node
{datatype data;
struct node *next;
}linklist;

linklist *CREATLISTF()
{char ch;linklist *head,*s;
head=NULL;
ch=getchar();
while(ch!='\n')
	{s=malloc(sizeof(linklist));
		s->data=ch;s->next=head;
		head=s;ch=getchar();
	}
return head;
}//ͷ�彨��0


linklist *CREATLISTR()
{char ch;linklist *head,*s,*r;
head=NULL;r=NULL;
ch=getchar();
while(ch!='\n')
	{s=malloc(sizeof(linklist));
	s->data=ch;
	if(head==NULL)head=s;
	else r->next=s;
	r=s;ch=getchar();
	}
if(r!=NULL)r->next=NULL;
return head;
}//β�彨��0


linklist *CREATLISTR1()
{char ch;linklist *head,*s,*r;
head=malloc(sizeof(linklist));r=head;
ch=getchar();
while(ch!='\n')
	{s=malloc(sizeof(linklist));
	s->data=ch;r->next=s;r=s;
	ch=getchar();
	}
r->next=NULL;
return head;
}//β�彨��1

linklist *GET(linklist *head,int i)
{int j;linklist *p;
p=head;j=0;
while((p->next!=NULL)&&(j<i))
{p=p->next;j++;}
if(i==j)return p;
else return NULL;
}//GET����0


INSERTAFTER(linklist *p,datatype x)
{linklist *s;
s=malloc(sizeof(linklist));
s->data=x;s->next=p->next;p->next=s;
}//�����0

INSERTBEFORE(linklist *head,linklist *p,datatype x)
{linklist *s,*q;
s=malloc(sizeof(linklist));
s->data=x;q=head;
while(q->next!=p)q=q->next;
s->next=p;q->next=s;
}//ǰ����0

INSERTBEFORE1(linklist *p,datatype x)
{linklist *s;
s=malloc(sizeof(linklist));
s->data=p->data;s->next=p->next;
p->data=x;p->next=s;
}//ǰ����1

DELETEAFTER(linklist *p)
{linklist *r;
r=p->next;
p->next=r->next;free(r);
}//ɾ�����0

DELETER(linklist *L,int i)
{linklist *p;int j;
j=i-1;p=GET(L,j);
if((p!=NULL)&&(p->next!=NULL))
	DELETEAFTER(p);
else //i<1 or i>n
printf("error");
}//ɾ����i���ڵ�
