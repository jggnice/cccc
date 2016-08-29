#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct polylink
{
	char() ch;       /*������*/
	float coef;  /* ϵ����*/         
	int expn;   /* ָ����*/                 
	struct polylink *next;  /* ����*/                                 
};
/*��ʼ������*/
polylink *initpoly()
{
	polylink *p;
	p = (polylink *)malloc(sizeof(polylink));
	if(p == NULL)
	{
		printf("memory error!");
		exit(0);
	}
	p->next = NULL;
	return p;
}
/*��������*/
void destroy_link(polylink *p)
{
	polylink *q;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}
/*����ʽ��������*/
polylink * creat_ploy(polylink *p)
{
	char() c[1];
	int i = 0, n=0;
	polylink *p1;
	p = initpoly();
	printf("input variable's name �����������\n");
	scanf("%s", c);		
	printf("input the polynomial's number �������ʽ������\n");
	scanf("%d", &n);  
	for(i = 0; i < n; i++)
	{
		p1 = (polylink *)malloc(sizeof(polylink));
		if(p1 == NULL)/*����ɹ�ʱ*/
		{
			printf("memory error!"); 
			exit(0);
		}
		printf("input the %dst's coefficient �����%d��ϵ����\n", i+1, i+1);
		scanf("%f", &p1->coef);
		printf("input the variable's index �������ָ����\n");
		scanf("%d", &p1->expn);
		p1->ch = c[0];
		p1->next = p->next;
		p->next = p1;
	}
	return p;
}
/*ɾ���ڵ㺯��*/
 polylink *delnode(polylink * h , polylink * maxp)      /*ɾ���ڵ㷵��ʣ�������׵�ַ*/   
{   
	polylink *t; 
	t = h;   
    while(t->next != maxp ) 
		t=t->next;				   /*��maxp ǰ�ڵ�t  */         
	t->next = maxp->next ;                /*ɾ��maxpmaxp���t��*/   
    maxp->next = NULL;   
    return h;                             /*������h ,���� */    
}   
/*�������*/
 void link_lenth(polylink *p, int &a)/* &����*/
 {
	while(p->next != NULL)
	{
        p = p->next;
		a++;
	}
 }

/*����*/
polylink *sort(polylink *h) 
{
	int  min;     /*����ָ��Сֵ*/ 
	polylink  *t=NULL, *minp=NULL, *head=NULL;
	if(h ->next == NULL)
	{
		printf("don't exist number");
		exit(0);
	}   
    while(h->next !=NULL)                 /*ֻҪ��ǰ����ѭ�� */  
    {   
        t= h->next;  // t ����ʱָ��   
        min=t->expn; minp=t;          /*�ѵ�ǰtֵ��С*/   
        while (t->next !=NULL)      /*ֻҪt�滹�нڵ�ѭ��*/   
        {   
			t=t->next ;              /*t���ƶ�*/   
            if (t->expn < min)      /*tֵ����maxn�������ֵ��λ��*/        
            {  
				min = t->expn;   
                minp=t;
			}    
        }                            /*�ҳ���ǰͷ��ʼ����ڵ� maxp*/   
        h = delnode(h, minp);           /*ɾ��minp�ڵ�,����ʣ������*/   
        minp->next=head;   /*ÿ��С�ڵ��ͷ���֮ǰ*/
		head = minp;	  /*head ���»ظ�����ͷ*/
	}
	h->next = head;     /*head ��ͷ�ڵ�֮*/
	return h;   
}
/*��Ԫ����ʽ��*/
polylink *poly_derivation(polylink *p)
{
	polylink *n, *q;
	q= p;
	if(p->next == NULL) 
	{
		printf("polynomial don't exist!\n");
	}
	while(p->next != NULL)
	{
		p = p->next;
		if(p->expn == 0 || p->coef == 0) /*ָ�������ϵ����ɾ��*/
		{
			q = delnode(q, p);
		}
	}
	n = q; /*����ɾ�����ýڵ�����֮ͷ��� ���ڷ���*/
	if(q->next == NULL)
	{
		printf("polynomial don't exist!\n");
	}
	while(q->next != NULL)
	{
		q = q->next;
		q->coef = q->coef * q->expn; /*ϵ����ָ��*/
		q->expn = q->expn - 1;	    /*ָ����*/
	}
	return n;
}
/*��ʾ����ʽ*/
void display_poly(polylink *p)
{
	int a;
	p = sort(p);  /*����*/
	while(p->next !=  NULL ) 
	{
		p = p->next;
		a = 1;
		if(p->coef < 0) a = 0;
		a ? printf(" +"): printf(" ");
		printf("%.1f%c^%d", p->coef, p->ch, p->expn);
	}
	printf("\n");
}

/*���Һ���*/
polylink *locate_link(polylink *p, int index)
{
	
	p = p->next;
	while(p != NULL && p->expn != index)
		p = p->next;
	if(p == NULL) 
		return NULL;
	else 
	    return p;
}
/*�˴�������*/
void creat(polylink *&p1, polylink *&p2)
{   
	p1 = creat_ploy(p1);				/*��������ʽ*/
	printf("another polynomial building:\n");
	p2 = creat_ploy(p2);				/*��������ʽ*/
	printf("first :\n");
	display_poly(p1);					/*��ʾ��������ʽ*/
	printf("the second:\n");
    display_poly(p2);					/*��ʾ��������ʽ*/
}
/*����ʽ���*/
polylink * poly_add(polylink *head1, polylink *head2, char() a)
{
	char ch[1];
	polylink *p1, *p2, *p, *r;
	p1 = head1;
	p2 = head2;
	if(a == '+')		/*�亯������ʱִ��*/
	{
		system("cls");
		creat(p1, p2);	/*����p1 p2*/
	}
	r = p1;
	while(r->next != NULL)
	{
		p1 = r->next;
		r = delnode(r, p1);				/*ɾ��p1*/
		p = locate_link(p2, p1->expn);  /*����p2���� ϵ������p1->expn�ڵ��з��ظõ���򷵻�NULL*/
		if(p != NULL)
			p->coef = p->coef + p1->coef;
		else			/*�ѽڵ�p1��������p2*/
		{
			
			p1->next = p2->next;
			p2->next = p1;
		}
	}
	if(a == '+')  /*�������߳�����ʱ����*/
	{
		printf("add result:\n");
	    display_poly(p2);  /*��ʾ*/
		printf("whether to derivat:y/n\n");
		scanf("%s", ch);   
		if( ch[0] == 'Y' || ch[0] == 'y')
		{
            p2 = poly_derivation(p2);
		    display_poly(p2);
			destroy_link(p2);  /*��������*/
		}
		else
			destroy_link(p2);/*��������*/
		getchar()();/*����Ļ��ʾͣ�����*/
		return NULL;
	}
	return p2;
}
/*����ʽ���*/
void poly_sub(polylink *p1, polylink *p2)
{
	char ch[1];
    polylink *n,  *p;
	system("cls");  /*����*/
	creat(p1, p2);
	p = p2;
	while(p->next != NULL)
	{
		p = p->next;
		p->coef = -1 * p->coef;
	}
	printf("\nsub 1st - 2st\n");
	n = poly_add(p1, p2, '-'); /*���ü����㺯��*/
	display_poly(n);
	printf("whether to derivat:y/n\n");
	scanf("%s", ch);
	if( ch[0] == 'Y' || ch[0] == 'y')	
	{
        n = poly_derivation(n);  /*��*/
	    display_poly(n);
		destroy_link(n);
	}
	else destroy_link(n);
	getchar()();
}
/*����ʽ���*/
polylink *multiply(polylink *p, float coef, int index)
{						/*����ϵ����ָ���ֱ���pÿ�ڵ����� ���ظ���*/
	polylink *q, *n;
	n = (polylink *)malloc(sizeof(polylink));
	n->next = NULL;			/*n��ͷ�ڵ�*/
	while(p->next != NULL)
	{
		p = p->next;
		q = (polylink *)malloc(sizeof(polylink));
		q->ch = p->ch;
		q->coef = coef * p->coef;
		q->expn = index + p->expn;
		q->next = n->next;
		n->next = q;			
	}
	return n;
}
/*����ʽ���������������ߴ���������*/
void run_mul(polylink *p1, polylink *p2, int num)
{
	int i = 0;
	char ch[1];
	polylink **p, *q;    /*��άָ���ÿ��multiply����������������*/
	p = (polylink **)malloc( num *sizeof(polylink));
    while(p1->next != NULL)
	{
		p1 = p1->next;
		p[i++] = multiply(p2, p1->coef, p1->expn); 
	}
	q = poly_add(p[0], p[1], '*');
	for(i = 2; i < num; i++)
	{
	   q = poly_add(q, p[i], '*');
	}
    printf("mul result:\n");
	display_poly(q);
	printf("whether to derivat:y/n\n");
	scanf("%s", ch);
	if( ch[0] == 'Y' || ch[0] == 'y')
	{
         q = poly_derivation(q);
		 display_poly(q);
		 destroy_link(q);
	}
	else destroy_link(q);
	getchar()();
}
void poly_mul(polylink *p1, polylink *p2)
{
	int num1 =0 , num2 = 0;		/*���ڴ��p1 p2��*/
	system("cls");
	creat(p1, p2);
    link_lenth(p1, num1);
	link_lenth(p2, num2);
	if(num2 >= num1) /*��������*/
	{
		run_mul(p1, p2, num1);
	}
	else
	{
		run_mul(p2, p1, num2);
	}
}   
/*ѡ����*/
int menu_select()() 
{
	int n; 
	printf("press enter key to enter the menu......"); /*���μ��������˵�*/ 
	getchar(); /*�Ӽ��̶�ȡ�ַ�,��ʾ����Ļ*/ 
    system("cls"); /*����*/ 
    printf("\n\n\n\n\n\n"); 
	printf("\t\t\tIt just for a variables\n\n");
	printf("\t*************************************MENU***********************\n\n"); 
	printf("\t\t\t1. ����ʽ��� add operation\n\n");
	printf("\t\t\t2. ����ʽ��� sub operation\n\n"); /*��ʾ*/ 
	printf("\t\t\t3. ����ʽ��� mul operation\n\n"); /*Ѱ��*/ 
	printf("\t\t\t4. �˳� Quit\n\n"); /*ɾ��*/ 
	printf("\t****************************************************************\n\n"); 
	do{ 
			printf("\n\t����ѡ��Enter your choice(1~4):"); 
			scanf("%d",&n); 
	}while(n < 1 || n > 4); /*ѡ����1~4֮��������*/ 
	return n; /*����ѡ�������������ݸ���������Ӧ����*/ 
} 
void main() 
{
	polylink *head1=NULL, *head2=NULL, *head3=NULL; /*head3���ô�*/
     
	for(;;) /*ѭ�����޴�*/ 
	{
		switch( menu_select()() ) 
		{ 
			case 1: head3 = poly_add(head1, head2, '+'); break;
			case 2: poly_sub(head1, head2);  break; 
			case 3: poly_mul(head1, head2); break; 
			case 4: exit(0); /*�˵�����ֵ4��������*/ 
		} 
	} 
}