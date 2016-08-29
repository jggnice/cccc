#include<stdio.h>  
void main ( )  /* 相减法求最大公约数 */  
{    
   int m, n, a, b;  
 printf("Input two integer numbers:\n");  
   scanf ("%d,%d", &a, &b);m=a; n=b;   
     /* a, b不相等，大数减小数，直到相等为止。*/   
   while ( a!=b)   
         if (a>b)  a=a-b;       
         else  b=b-a;  
   printf("The largest common divisor:%d\n", a);  
   printf("The least common multiple:%d\n", m*n/a);  
}  