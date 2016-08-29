#include"stdio.h"
#define N 10
typedef struct {int key;char other;}rectype;
rectype R[N];
void print(int l,int h,int k)
{	
	int i;printf("\n");
		for(i=0;i<N;i++)
 { if((k!=-1)&&(i==l))
		printf("  [%d",R[i].key);
else if((k!=-1)&&(i==h))
		printf("%4d]",R[i].key);
else printf("%4d",R[i].key);
 }
}
void swap(rectype *A,rectype *B)
{
 rectype temp;
 temp=*A;*A=*B;*B=temp;
}
int partition(rectype *A,int l,int h)
{
    int i,j,mid;rectype temp;

    i=l;j=h;mid=(l+h)/2;print(l,h,0);
printf("\nchange: (%d,%d,%d)",A[l].key,A[mid].key,A[h].key);
    if(A[l].key>A[h].key)swap(&A[l],&A[h]);
    if(A[l].key<A[mid].key)swap(&A[l],&A[mid]);
    if(A[l].key>A[h].key)swap(&A[l],&A[h]);
printf("-->(%d,%d,%d)",A[l].key,A[mid].key,A[h].key);print(l,h,0);
    temp=A[i];/*left room i*/
    do
    {
        while((A[j].key>=temp.key)&&(i<j))
        j--;
        if(i<j)A[i++]=A[j]; /*go to room i and left room j*/
        while((A[i].key<=temp.key)&&(i<j))
        i++;
        if(i<j)A[j--]=A[i]; /*go to room j and left room i*/
    }while(i!=j);
    A[i]=temp;/*go to room i*/
    return i;
}/*partition*/
void Quicksort(rectype *R,int s1,int t1)
{
    int i;
    if(s1<t1)
    {
        i=partition(R,s1,t1);
        Quicksort(R,s1,i-1);
        Quicksort(R,i+1,t1);
    }
}/*Quicksort*/
void findj(void)
{  int pos,
  j,
  l=0,h=N-1;
  printf("input j to find:");
  scanf("%d",&j);
  if(j<1||j>N)
{printf("\nmust between 1 and %d,input 2 to continue:",N);return;}
   while(pos+1!=j)
  {pos=partition(R,l,h);printf("\npos=%d",pos+1); 
   if(pos+1==j)
{printf("\nsmall %d is --%d--",j,R[pos].key);}
   else if(pos+1<j){l=pos+1;}
   else {h=pos-1;
  }

}


}
void setR(void)
{int i;
for(i=0;i<N;i++)
   	R[i].key=rand()%(100);
   print(0,0,-1);printf("\n");
} 



int main()
{   int i;char ch;
    srand(time(NULL));          /*初始化随机数*/
    printf("R[n]:");
    setR();
printf("functions:\n1:reset R[n]\t2:find smaller j\t3:quicksort\n$:exit");
while((ch=getchar())!='$')
{
   switch(ch)
   {
      case '1':setR();break;
      case '2':findj();break;
      case '3':Quicksort(R,0,N-1);printf("\nfinal:");print(0,0,-1);break;
      case '\n':;
      case '$':break;
      default:printf("illeagal input\n"); 
   }
}

    printf("ok!");getch();return 0;
}
