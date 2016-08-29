/*
 * File:   main.c
 * Author: 旺
 *
 * Created on 2015年10月20日, 下午8:17
 */

#include <stdio.h>
#include <stdlib.h>
#include"lsw05.h"
#define PI 3.1415926
/*
 *
 */
int main(int argc, char** argv)
{

	FILE *fp1,*fp2;

//*********************checkblock***********************************
	if ((fp1 = fopen("poly1.txt", "rt")) == NULL)
	{
		printf("Can't open file.\n");
		//system("pause");
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen("poly2.txt", "rt")) == NULL)
	{
		printf("Can't open file.\n");
		//system("pause");
		exit(EXIT_FAILURE);
	}

//*********************checkblock***********************************

	poly_t *p1 ,*p2, *p1_copy1,*p1_copy2,*p3,*mul_test;

	p1 = creat_poly(fp1);
	p2 = creat_poly(fp2);
	p1 = (poly_t *)merge(p1);
	p2 = (poly_t *)merge(p2);
	p1_copy1 = (poly_t *)copy_poly(p1);
	p1_copy2 = (poly_t *)copy_poly(p1);
	mul_test = (poly_t *)mul_poly_more(p1, p2);
	mul_test = (poly_t *)merge(mul_test);
	add_poly(p1_copy2,p2);
	p1_copy2 = (poly_t *)merge(p1_copy2);

	//***************test value at poly************
	printf("\n************test value at poly1**************");
	poly_value_at(p1_copy1,PI);
	//***************test differential_poly*********
	differential_poly(p1_copy1);
	printf("\n************test differential_poly of poly1**************\n");
	print_poly(p1_copy1);
	//***************test add *********************
	printf("\n************add  poly1 + poly2****************\n");
	print_poly(p1_copy2);
	//***************multiply**********************
	printf("\n************multiply= poly1 * poly2***********\n");
	print_poly(mul_test);
	//*************** clear *****************
	fclose(fp1);
	fclose(fp2);
	return (EXIT_SUCCESS);
}