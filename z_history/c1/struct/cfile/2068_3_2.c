#include"stdio.h"
#include"stdlib.h"
/*只有尾指针的循环队列*/ 
typedef int datatype;
typedef struct node
{datatype data;
struct node *next;
}linkqueue;

linkqueue *creat(void)
{linkqueue *rear;
    rear=(linkqueue *)malloc(sizeof(linkqueue));
    rear->next=rear;return rear;
}

int emptyqueue(linkqueue *S)
{return((S->next->next)==S->next);} 

    

linkqueue *enqueue(linkqueue *rear,datatype x)
{linkqueue *p;
   p=(linkqueue *)malloc(sizeof(linkqueue));
   p->next=rear->next;rear->next=p;
   rear=rear->next;rear->data=x;
   return rear;
}
datatype outqueue(linkqueue *rear)
{linkqueue *p;
if(emptyqueue(rear)){printf("\n empty list");return NULL;}
else{    p=rear->next;
    rear->next=rear->next->next;printf("\n%d is out\n",rear->next->data);
    free(p);return(rear->next->data);
	}
}


 
void list(linkqueue *rear)
{linkqueue *L,*p;L=rear->next;p=L->next;
    if(p==L)
	{printf("\n empty list");return;}
    else {
    while(p!=L)
      {printf("%d ",p->data);
       p=p->next;
      }
         }
}

void delete1(linkqueue *rear)
{linkqueue *p,*q;
p=rear->next;
while(p!=rear)
    {q=p->next;
    free(p);
    p=q;
    }free(rear); 
}
main()
{char numstr[20];linkqueue *S;
S=creat();
printf("\ncreat queue\nint for every data\nsingle @ to end\n");
gets(numstr);
       while(numstr[0]!='@')
  {S=enqueue(S,atoi(numstr));/*here is the cake*/
  gets(numstr);}
  list(S);
outqueue(S);
printf("\nnow list queue\n");list(S);
delete1(S);getch();
}
