#include "stdio.h"

#include "stdlib.h"

#include "conio.h"

typedef struct Item{
  double  coef;//ϵ��
  int     expn;//ָ��
  struct Item *next;
  }Item,*Polyn;

#define CreateItem(p) p=(Item *)malloc(sizeof(Item));
#define DeleteItem(p) free((void *)p);

/************************************************************/
/*                     �ж�ѡ����                        */
/************************************************************/
int Select(char *str)
  { char ch;
    printf("%s\n",str);
    printf("Input Y or N:");
    do{ ch=getch();
	}while(ch!='Y'&&ch!='y'&&ch!='N'&&ch!='n');
    printf("\n");
    if(ch=='Y'||ch=='y') return(1);
    else return(0);
    }
/************************************************************/
/*                ����λ�ö�λ����                         */
/**************************************************************/
int InsertLocate(Polyn h,int expn,Item **p)
  { Item *pre,*q;
    pre=h;
    q=h->next;
    while(q&&q->expn<expn) 
      { pre=q;
        q=q->next;
	    }
    if(!q)
      { *p=pre;
	    return(1);
	    }
    else if(q->expn==expn)
      { *p=q;
	    return(0);
	    }
    else
      { *p=pre;
	    return(-1);
        }
    }
/************************************************************/
/*                     �����㺯��                        */
/************************************************************/
void insert(Item *pre,Item *p)
{
    p->next=pre->next;
    pre->next=p;
    }
/************************************************************/
/*                     �������ʽ                          */
/************************************************************/
Polyn Input(void)
{
  double  coef;
  int     expn,flag;
  Item *h,*p,*q,*pp;
  CreateItem(h);//����ͷ���
  h->next=NULL;
  printf("input coef and expn(if end ,expn=-1)\n");
  while(1)
  {
    scanf("%lf%d",&coef,&expn); //�������ʽ��ϵ����ָ��
    if(expn==-1) break;         //��ָ��Ϊ������ʾ�������
    if(InsertLocate(h,expn,&pp))//����ֵ�Ǳ�ʾ�����½��
     { CreateItem(p);
       p->coef=coef;
       p->expn=expn;
       insert(pp,p);
     }
     else if(Select("has the same expn,Replace older value?")) 
	  pp->coef=coef;  //ָ����ͬ���滻ϵ��
   }
  return h;
  }
/************************************************************/
/*                     ��������ʽ                          */
/************************************************************/
void Destroy(Polyn h)
{
  Item *p=h,*q;
  while(p!=NULL)
  {
    q=p;
    p=p->next;
    DeleteItem(q);
    }
  }
/************************************************************/
/*                     �������ʽ                          */
/************************************************************/
void Output(Polyn h,char *title)
{
  int flag=1;
  Item *p=h->next;
  printf("%s=",title);
  while(p)
  { if(flag)    //��ʾ�Ƿ��Ƕ���ʽ�ĵ�һ��
      { flag=0;
	   if(p->expn==0) 	printf("%.2lf",p->coef);
	   else printf("%.2lfx^%d",p->coef,p->expn);
	   }
    else
      { if(p->coef>0) printf("+");
	      if(p->expn==0) 	printf("%.2lf",p->coef);
	      else printf("%.2lfx^%d",p->coef,p->expn);
	      }
    p=p->next;
    }
 printf("\n");
 }
/************************************************************/
/*                     �ж���������ʽ��Ĺ�ϵ              */
/************************************************************/
int ItemComp(Item x,Item y)
{ if(x.expn<y.expn)
     return(-1);
  else if(x.expn==y.expn)
     return(0);
  else return(1);
  }
/************************************************************/
/*                   ������ʽ����ʽ���                    */
/************************************************************/
Polyn AddPolyn(Polyn h1,Polyn h2) 
{
  Item *head,*last,*pa=h1->next,*pb=h2->next,*s;
  CreateItem(head);
  head->next=NULL;
  last=head;
  while(pa&&pb){
	  CreateItem(s);
	  last->next=s;
	  last=s;
	  switch (ItemComp(*pa,*pb))
	  {
	  case -1:last->coef=pa->coef;last->expn=pa->expn;pa=pa->next;break;
	  case 0:last->coef=pa->coef+pb->coef;last->expn=pa->expn;pa=pa->next;pb=pb->next;break;
	  case 1:last->coef=pb->coef;last->expn=pb->expn;pb=pb->next;break;
	  }
  }
  if(pa){while(pa){/*��ʣ��ڵ����*/
	  CreateItem(s);last->next=s;last=s;last->coef=pa->coef;last->expn=pa->expn;pa=pa->next;}}
  if(pb){while(pb){/*��ʣ��ڵ����*/
	  CreateItem(s);last->next=s;last=s;last->coef=pb->coef;last->expn=pb->expn;pb=pb->next;}}
  last->next=NULL;
  return head;
}
/************************************************************/
/*                   ������ʽ����ʽ���                    */
/************************************************************/
Polyn SubtractPolyn(Polyn h1,Polyn h2) 
{ Item *head,*last,*pa=h1->next,*pb=h2->next,*s;
  CreateItem(head);
  head->next=NULL;
  last=head;
  while(pa&&pb){
	  CreateItem(s);
	  last->next=s;
	  last=s;
	  switch (ItemComp(*pa,*pb))
	  {
	  case -1:last->coef=pa->coef;last->expn=pa->expn;pa=pa->next;break;
	  case 0:last->coef=pa->coef-pb->coef;last->expn=pa->expn;pa=pa->next;pb=pb->next;break;
	  case 1:last->coef=-(pb->coef);last->expn=pb->expn;pb=pb->next;break;
	  }
  }
  if(pa){while(pa){/*��ʣ��ڵ����*/
	  CreateItem(s);last->next=s;last=s;last->coef=pa->coef;last->expn=pa->expn;pa=pa->next;}}
  if(pb){while(pb){/*��ʣ��ڵ����*/
	  CreateItem(s);last->next=s;last=s;last->coef=-(pb->coef);last->expn=pb->expn;pb=pb->next;}}
  last->next=NULL;
  return head;
   }
/************************************************************/
/*                   ������ʽ����ʽ���                    */
/************************************************************/
Polyn MultPolyn(Polyn h1,Polyn h2)  //��������ʽ���
{ int item,expn;
  Item *head,*pa,*pb=h2->next,*s,*pp;
  double coef;
  CreateItem(head);
  head->next=NULL;
  while(pb){
	  pa=h1->next;
	  while(pa){
		  expn=pa->expn+pb->expn;
		  coef=pa->coef*pb->coef;
		  if(InsertLocate(head,expn,&pp))
		  {
			  CreateItem(s); 
			  s->coef=coef;
			  s->expn=expn;
			  insert(pp,s);
		  }
		  else
			  pp->coef=pp->coef+pa->coef;
		  pa=pa->next;
	  }
	  pb=pb->next;
  }
  return head;
}   
/************************************************************/
/*                      �˵�ѡ��                           */
/************************************************************/
int menu(void)
  { int num;
    system("cls");
    printf("%20c1--create P(x)\n",' ');
    printf("%20c2--create Q(x)\n",' ');
    printf("%20c3--p(x)+Q(x)\n",' ');
    printf("%20c4--P(x)-Q(x)\n",' ');
    printf("%20c5--p(x)*Q(x)\n",' ');
    printf("%20c6--print P(x)\n",' ');
    printf("%20c7--print Q(x)\n",' ');
    printf("%20c8--print P(x)+Q(x)\n",' ');
    printf("%20c9--print P(x)-Q(x)\n",' ');
    printf("%20c10--print P(x)*Q(x)\n",' ');
    printf("%20c11--Quit\n",' ');
    printf("         please select 1,2,3,4,5,6,7,8,9,10,11:");
      do{
	  scanf("%d",&num);
	  }while(num<1 || num>11);
    return(num);
    }
/************************************************************/
/*                  �ж϶���ʽ�Ƿ����                     */
/************************************************************/
int PolynNotEmpty(Polyn h,char *p)
  { if(h==NULL)
      { printf("%s is not exist!\n",p);
        getchar();
	return(0);
	    }
     else return(1);
     }
/************************************************************/
/*                        ������                           */
/************************************************************/
void main()
{ int num;
  Polyn  h1=NULL; //ָ��p(x) ָ��
  Polyn  h2=NULL; //ָ��Q(x) ָ��
  Polyn  h3=NULL; //ָ��P(x)+Q(x) ָ��
  Polyn  h4=NULL; //ָ��P(x)-Q(x) ָ��
  Polyn  h5=NULL; //ָ��P(x)*Q(x) ָ��
  while(1)
    { num=menu();
      getchar();
      switch(num)
       {
	 case 1:  //�����һ������ʽ��������ʽ���ڣ����ȳ���Ȼ��������
	    if(h1!=NULL)
	      { if(Select("P(x) is not Empty,Create P(x) again?"))
		 { Destroy(h1);
		   h1=Input();
		   }
		}
	    else h1=Input();
            break;
	 case 2:  //����ڶ�������ʽ��������ʽ���ڣ����ȳ���Ȼ��������
	    if(h2!=NULL)
	      { if(Select("Q(x) is not Empty,Create Q(x) again?"))
		 { Destroy(h2);
		   h2=Input();
		   }
		}
	    else h2=Input();
	    break;
	 case 3:  //������ʽ���
	    if(PolynNotEmpty(h1,"p(x)")&&PolynNotEmpty(h2,"Q(X)"))//�ж�������ʽ���ǿ�
	      {h3=AddPolyn(h1,h2);
	       Output(h3,"P(x)+Q(X)");
           printf("P(x)+Q(x) has finished!\n");
	       getchar();
               }
	    break;
	 case 4:  //������ʽ���
	    if(PolynNotEmpty(h1,"p(x)")&&PolynNotEmpty(h2,"Q(X)"))
	      { h4=SubtractPolyn(h1,h2);
	        Output(h4,"P(x)-Q(x)");
                printf("P(x)-Q(x) has finished!\n");
		getchar();
		}
	    break;
	 case 5:  //������ʽ���
            if(PolynNotEmpty(h1,"p(x)")&&PolynNotEmpty(h2,"Q(X)"))
	      { h5=MultPolyn(h1,h2);
            Output(h5,"P(x)*Q(x)");
	        printf("P(x)*Q(x) has finished!\n");
	        getchar();
           }
	    break;
     case 6: //��ʾ��һ������ʽ
	    if(PolynNotEmpty(h1,"p(x)"))
	       { Output(h1,"P(x)");
		     getchar();
		    }
	    break;
	 case 7: //��ʾ�ڶ�������ʽ
	    if(PolynNotEmpty(h2,"Q(x)"))
	      { Output(h2,"Q(x)");
		    getchar();
		   }
	    break;
	 case 8: //��ʾ��ӽ������ʽ
	    if(PolynNotEmpty(h3,"P(x)+Q(x)"))
	      { Output(h3,"P(x)+Q(x)");
		    getchar();
		   }
	    break;
	 case 9: //��ʾ����������ʽ
	    if(PolynNotEmpty(h4,"P(x)-Q(x)"))
	      { Output(h4,"P(x)-Q(x)");
		    getchar();
		   }
	    break;
	 case 10: //��ʾ��˽������ʽ
	    if(PolynNotEmpty(h5,"P(x)*Q(x)"))
	      { Output(h5,"P(x)*Q(x)");
		    getchar();
		   }
	    break;
	 case 11: //�����������С�����ǰӦ�ȳ����Ѵ��ڵĶ���ʽ
	    if(h1!=NULL) Destroy(h1);
	    if(h2!=NULL) Destroy(h2);
	    if(h3!=NULL) Destroy(h3);
	    if(h4!=NULL) Destroy(h4);
	    if(h5!=NULL) Destroy(h5);
	 }
      if(num==11) break;
      }
  getch();
  }