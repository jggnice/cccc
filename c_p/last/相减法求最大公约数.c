#include<stdio.h>  
void main ( )  /* ����������Լ�� */  
{    
   int m, n, a, b;  
 printf("Input two integer numbers:\n");  
   scanf ("%d,%d", &a, &b);m=a; n=b;   
     /* a, b����ȣ�������С����ֱ�����Ϊֹ��*/   
   while ( a!=b)   
         if (a>b)  a=a-b;       
         else  b=b-a;  
   printf("The largest common divisor:%d\n", a);  
   printf("The least common multiple:%d\n", m*n/a);  
}  