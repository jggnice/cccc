#include "stdio.h"

main()
{
    char  s;
    int cnt = 0;

    printf("please enter the sentence\n");
    
    while(s!='\n')
    {s=getchar();
        if(s==' ') cnt++;
       
    }
    printf("the sectence have %d word\n",cnt);
}