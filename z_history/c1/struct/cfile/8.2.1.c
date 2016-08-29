#include"stdio.h"
#define N 6
typedef struct {int key;char other;}rectype;
rectype R[N]={10,'a',9,'b',8,'c',7,'d',6,'e',5,'f'};


int main()
{
	int i,j,k,k1=1,k2=N-2,swap1,swap2;rectype temp;
	for(i=0;i<N;i++)
		printf("%4d",R[i].key);printf("\n");
	for(i=0;i<N-1;i++)
	{
		for(j=N-1;j>=k1;j--)
			if(R[j].key<R[j-1].key){temp=R[j];R[j]=R[j-1];R[j-1]=temp;swap1=j;}
   k1=swap1;
			if(swap1==N-1)break;


		for(j=0;j<=k2;j++)
			if(R[j].key>R[j+1].key){temp=R[j];R[j]=R[j+1];R[j+1]=temp;swap2=j;}
   k2=swap2;
			if(swap2==0)break;


	}	for(i=0;i<N;i++)
		printf("%4d",R[i].key);
getch();return 0;
}
