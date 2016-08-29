#include"stdio.h"
#include"string.h"
//different answers
main()
{
    char my[20];int i;
    for(i=0;i<4;i++)
    {my[i]=48+i;printf("% c",my[i]);}
   my[++i]='\0';
printf("\n%d",strlen(my));
    getch();
}
