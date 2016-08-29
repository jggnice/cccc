#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct polylink
{
	char() ch;       /*变量名*/
	float coef;  /* 系数域*/         
	int expn;   /* 指数域*/                 
	struct polylink *next;  /* 链域*/                                 
};
/*初始化链表*/
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
/*销毁链表*/
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
/*多项式存入链表*/
polylink * creat_ploy(polylink *p)
{
	char() c[1];
	int i = 0, n=0;
	polylink *p1;
	p = initpoly();
	printf("input variable's name 输入变量名：\n");
	scanf("%s", c);		
	printf("input the polynomial's number 输入多项式项数：\n");
	scanf("%d", &n);  
	for(i = 0; i < n; i++)
	{
		p1 = (polylink *)malloc(sizeof(polylink));
		if(p1 == NULL)/*分配成功时*/
		{
			printf("memory error!"); 
			exit(0);
		}
		printf("input the %dst's coefficient 输入第%d项系数：\n", i+1, i+1);
		scanf("%f", &p1->coef);
		printf("input the variable's index 输入变量指数：\n");
		scanf("%d", &p1->expn);
		p1->ch = c[0];
		p1->next = p->next;
		p->next = p1;
	}
	return p;
}
/*删除节点函数*/
 polylink *delnode(polylink * h , polylink * maxp)      /*删除节点返回剩下链表首地址*/   
{   
	polylink *t; 
	t = h;   
    while(t->next != maxp ) 
		t=t->next;				   /*找maxp 前节点t  */         
	t->next = maxp->next ;                /*删除maxpmaxp面接t面*/   
    maxp->next = NULL;   
    return h;                             /*链首依h ,返回 */    
}   
/*求表长函数*/
 void link_lenth(polylink *p, int &a)/* &引用*/
 {
	while(p->next != NULL)
	{
        p = p->next;
		a++;
	}
 }

/*排序*/
polylink *sort(polylink *h) 
{
	int  min;     /*保存指数小值*/ 
	polylink  *t=NULL, *minp=NULL, *head=NULL;
	if(h ->next == NULL)
	{
		printf("don't exist number");
		exit(0);
	}   
    while(h->next !=NULL)                 /*只要当前链空循环 */  
    {   
        t= h->next;  // t ：临时指针   
        min=t->expn; minp=t;          /*把当前t值作小*/   
        while (t->next !=NULL)      /*只要t面还有节点循环*/   
        {   
			t=t->next ;              /*t往移动*/   
            if (t->expn < min)      /*t值大于maxn则记下其值和位置*/        
            {  
				min = t->expn;   
                minp=t;
			}    
        }                            /*找出当前头开始链大节点 maxp*/   
        h = delnode(h, minp);           /*删除minp节点,返回剩下链表*/   
        minp->next=head;   /*每次小节点接头结点之前*/
		head = minp;	  /*head 重新回该链开头*/
	}
	h->next = head;     /*head 接头节点之*/
	return h;   
}
/*对元多项式求导*/
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
		if(p->expn == 0 || p->coef == 0) /*指数零或者系数零删除*/
		{
			q = delnode(q, p);
		}
	}
	n = q; /*保存删除无用节点链表之头结点 用于返回*/
	if(q->next == NULL)
	{
		printf("polynomial don't exist!\n");
	}
	while(q->next != NULL)
	{
		q = q->next;
		q->coef = q->coef * q->expn; /*系数乘指数*/
		q->expn = q->expn - 1;	    /*指数减*/
	}
	return n;
}
/*显示多项式*/
void display_poly(polylink *p)
{
	int a;
	p = sort(p);  /*排序*/
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

/*查找函数*/
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
/*了代码重用*/
void creat(polylink *&p1, polylink *&p2)
{   
	p1 = creat_ploy(p1);				/*创建多项式*/
	printf("another polynomial building:\n");
	p2 = creat_ploy(p2);				/*创建多项式*/
	printf("first :\n");
	display_poly(p1);					/*显示创建多项式*/
	printf("the second:\n");
    display_poly(p2);					/*显示创建多项式*/
}
/*多项式相加*/
polylink * poly_add(polylink *head1, polylink *head2, char() a)
{
	char ch[1];
	polylink *p1, *p2, *p, *r;
	p1 = head1;
	p2 = head2;
	if(a == '+')		/*其函数调用时执行*/
	{
		system("cls");
		creat(p1, p2);	/*创建p1 p2*/
	}
	r = p1;
	while(r->next != NULL)
	{
		p1 = r->next;
		r = delnode(r, p1);				/*删除p1*/
		p = locate_link(p2, p1->expn);  /*查找p2否有 系数等于p1->expn节点有返回该点否则返回NULL*/
		if(p != NULL)
			p->coef = p->coef + p1->coef;
		else			/*把节点p1插入链表p2*/
		{
			
			p1->next = p2->next;
			p2->next = p1;
		}
	}
	if(a == '+')  /*被减或者乘运算时调用*/
	{
		printf("add result:\n");
	    display_poly(p2);  /*显示*/
		printf("whether to derivat:y/n\n");
		scanf("%s", ch);   
		if( ch[0] == 'Y' || ch[0] == 'y')
		{
            p2 = poly_derivation(p2);
		    display_poly(p2);
			destroy_link(p2);  /*销毁链表*/
		}
		else
			destroy_link(p2);/*销毁链表*/
		getchar()();/*让屏幕显示停运算结*/
		return NULL;
	}
	return p2;
}
/*多项式相减*/
void poly_sub(polylink *p1, polylink *p2)
{
	char ch[1];
    polylink *n,  *p;
	system("cls");  /*清屏*/
	creat(p1, p2);
	p = p2;
	while(p->next != NULL)
	{
		p = p->next;
		p->coef = -1 * p->coef;
	}
	printf("\nsub 1st - 2st\n");
	n = poly_add(p1, p2, '-'); /*调用加运算函数*/
	display_poly(n);
	printf("whether to derivat:y/n\n");
	scanf("%s", ch);
	if( ch[0] == 'Y' || ch[0] == 'y')	
	{
        n = poly_derivation(n);  /*求导*/
	    display_poly(n);
		destroy_link(n);
	}
	else destroy_link(n);
	getchar()();
}
/*多项式相乘*/
polylink *multiply(polylink *p, float coef, int index)
{						/*传入系数和指数分别与p每节点运算 返回该链*/
	polylink *q, *n;
	n = (polylink *)malloc(sizeof(polylink));
	n->next = NULL;			/*n作头节点*/
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
/*多项式相乘所用另外了提高代码重用性*/
void run_mul(polylink *p1, polylink *p2, int num)
{
	int i = 0;
	char ch[1];
	polylink **p, *q;    /*二维指针存每次multiply（）函数返回链表*/
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
	int num1 =0 , num2 = 0;		/*用于存放p1 p2表长*/
	system("cls");
	creat(p1, p2);
    link_lenth(p1, num1);
	link_lenth(p2, num2);
	if(num2 >= num1) /*根据链表*/
	{
		run_mul(p1, p2, num1);
	}
	else
	{
		run_mul(p2, p1, num2);
	}
}   
/*选择函数*/
int menu_select()() 
{
	int n; 
	printf("press enter key to enter the menu......"); /*按任键进入主菜单*/ 
	getchar(); /*从键盘读取字符,显示于屏幕*/ 
    system("cls"); /*清屏*/ 
    printf("\n\n\n\n\n\n"); 
	printf("\t\t\tIt just for a variables\n\n");
	printf("\t*************************************MENU***********************\n\n"); 
	printf("\t\t\t1. 多项式相加 add operation\n\n");
	printf("\t\t\t2. 多项式相减 sub operation\n\n"); /*显示*/ 
	printf("\t\t\t3. 多项式相乘 mul operation\n\n"); /*寻找*/ 
	printf("\t\t\t4. 退出 Quit\n\n"); /*删除*/ 
	printf("\t****************************************************************\n\n"); 
	do{ 
			printf("\n\t输入选择Enter your choice(1~4):"); 
			scanf("%d",&n); 
	}while(n < 1 || n > 4); /*选择项1~4之间则重输*/ 
	return n; /*返回选择项主函数根据该数调用相应函数*/ 
} 
void main() 
{
	polylink *head1=NULL, *head2=NULL, *head3=NULL; /*head3作用大*/
     
	for(;;) /*循环无限次*/ 
	{
		switch( menu_select()() ) 
		{ 
			case 1: head3 = poly_add(head1, head2, '+'); break;
			case 2: poly_sub(head1, head2);  break; 
			case 3: poly_mul(head1, head2); break; 
			case 4: exit(0); /*菜单返回值4则程序结束*/ 
		} 
	} 
}