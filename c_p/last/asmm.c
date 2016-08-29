#include <stdio.h>  
#include<stdlib.h>  
  
int main()  
{  
    int a=1,b=2,c=3;  
  
    _asm  
{  
    push eax  
    mov eax,a  
    add eax,b  
    add eax,c  
    mov a,eax  
    pop eax  
}  
  
    printf("%d",a);  
    system("pause");  
    return 0;  
} 