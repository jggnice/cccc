/*
 * File:   lsw05.h
 * Author: 旺
 *
 * Created on 2015年10月20日, 下午8:19
 */

#ifndef LSW05_H
#define	LSW05_H
#include<stdio.h>
typedef struct polynomial
{
	double coef;
	int pow;
	struct polynomial *	next;
} poly_t;

poly_t * creat_poly(FILE *fp);
void add_poly(poly_t *p1, poly_t *p2);
void print_poly(poly_t * temp);
#endif	/* LSW05_H */