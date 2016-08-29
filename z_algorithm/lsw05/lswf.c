#include"lsw05.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define MAXPOLY 20
poly_t * copy_poly(poly_t * p1)
{
	poly_t *p,*H,*temp ,*tail ;
	H = (poly_t *)malloc(sizeof(poly_t));
	tail = H ;
	p=(p1)->next;
	while(p != NULL)
	{
		temp = (poly_t *)malloc(sizeof(poly_t));
		tail->next = temp;
		tail=temp;
		tail->coef=p->coef;
		tail->pow=p->pow;
		p = p->next;
	}
	tail->next=NULL;
	return H;
}

poly_t * creat_poly(FILE *fp)
{
	int poly_length;
	double coef;
	int pow;
	int ii;
	poly_t  *L,*tail,*temp;
	rewind(fp);

	fscanf(fp,"%d",&poly_length);
	L=(poly_t *)malloc(sizeof(poly_t));/*L= new head*/
	tail=L;

	for(ii = 0; ii<poly_length; ii++)
	{
		temp = (poly_t *)malloc(sizeof(poly_t));/*temp = new node*/

		fscanf(fp,"%lf%d",&coef, &pow);

		tail->next = temp;
		tail=temp;
		tail->coef=coef;
		tail->pow=pow;

	}
	tail->next=NULL;
	return L;
}

void add_poly(poly_t *p1, poly_t *p2)
{
	poly_t * temp = p1;
	while(temp->next != NULL)temp = temp->next;
	temp->next = p2->next;

	p2 = NULL;
}

void mul_poly_once(poly_t *p1, poly_t *p2)
{
	poly_t *p;
	p=p1->next;
	while(p != NULL)
	{
		p->coef *= p2->coef;
		p->pow += p2->pow;
		p = p->next;
	}
}

poly_t * mul_poly_more(poly_t *p1, poly_t *p2)
{
	//int count = 1;
	poly_t *p;
	poly_t *tempp;
	poly_t *copy_p1=(poly_t *)copy_poly(p1);
	if(p1->next == NULL ) return NULL;
	p=p2->next;
	if(!p)
	{
		return NULL;
	}
	mul_poly_once( p1, p );
	if(p)p=p->next;

	while(p != NULL)
	{

		tempp = (poly_t *)copy_poly(copy_p1);
		//printf("copy Version(%d) = ",count++);print_poly(tempp );

		mul_poly_once( tempp, p );
		//printf("\ncopy mul =");print_poly(tempp );

		add_poly(p1,tempp);
		//printf("\nadd copy= ");print_poly(p1);
		p = p->next;

	}
	return p1;
}

void print_poly(poly_t * temp)
{
	if(!temp)
	{
		printf("0");
		return;
	}
	if (temp->next == NULL)
	{
		printf("0");
		return;
	}

	while(temp->next != NULL)
	{
		temp = temp->next;
		printf("%lf %d\n",temp->coef,temp->pow);
	}
}

poly_t * merge(poly_t *L)
{
	poly_t *p;
	poly_t *H = (poly_t *)malloc(sizeof(poly_t));/*H= new head*/
	poly_t *tail,*temp;
	double cc[MAXPOLY+1]= {0.0};
	tail = H;
	int ii=0;

	p=L->next;
	if(!p)
	{
		return L;
	}

	while(p != NULL)
	{
		cc[p->pow] += p->coef;
		p = p->next;
	}
	for(ii=0; ii<MAXPOLY+1; ii++)
	{
		if(cc[ii])
		{
			temp = (poly_t *)malloc(sizeof(poly_t));/*temp = new node*/
			tail->next = temp;
			tail=temp;
			tail->coef = cc[ii];
			tail->pow = ii;
		}
	}
	tail->next=NULL;
	return H;

}
void differential_poly(poly_t *L)
{
	poly_t *p;
	p=L->next;
	while(p != NULL)
	{
		if(p->pow==0)p->coef = 0.0;
		else
		{
			p->coef = p->coef * p->pow;
			p->pow --;
		}
		p = p->next;
	}
}
double poly_value_at(poly_t *L,double x)
{
	poly_t *p;
	p=L->next;
	double sum = 0.0;
	while(p != NULL)
	{
		sum += pow(x,p->pow)*(p->coef);
		p = p->next;
	}
	printf("\nvalue at %f=%14f",x,sum);
	return sum;
}