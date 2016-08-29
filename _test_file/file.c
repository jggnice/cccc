#include"stdio.h"
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])

{
 FILE *fp;
 int i;
 char a[100], b[100],ch;
 if(argc<2){printf("not enough parameters");system("pause");return 0;}
 if ((fp = fopen(argv[1], "rt")) == NULL)
   {
      printf("Can't open file.\n");system("pause");
      exit(EXIT_FAILURE);
   }
 fscanf(fp,"%s",a);
//  fgets(a,10,fp);
  printf("%s",a);
  
  fclose(fp);system("pause");
return 0;  
}