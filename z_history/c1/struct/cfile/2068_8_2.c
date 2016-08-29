#include"stdio.h"
#include"time.h" 
#define N 10
typedef struct {int key;char other;}rectype;
rectype R[N];
int  key[N]={10,2,3,4,5,6,7,8,9,1};

void print(int k)
{	
	int i;printf("\n");
		for(i=0;i<N;i++)
 { if(i!=k||k==-1)
		printf("%4d",R[i].key);
  else printf(" [%d]",R[i].key);
 }
}
int main()
{
	int i,j,flag,k1=1,k2=N-2,swap1,swap2;rectype temp;


	for(i=0;i<N;i++)
	R[i].key=key[i];

	print(-1);printf("\n");
	for(i=0;i<N-1;i++)
	{flag=0;
		for(j=N-1;j>=k1;j--)
			if(R[j].key<R[j-1].key){temp=R[j];R[j]=R[j-1];R[j-1]=temp;swap1=j;flag=1;}
			k1=swap1;print(swap1-1);
			if(!flag)break;printf("\tto left");
	flag=0;
		for(j=0;j<=k2;j++)
			if(R[j].key>R[j+1].key){temp=R[j];R[j]=R[j+1];R[j+1]=temp;swap2=j;flag=1;}
   k2=swap2;print(swap2+1);


			if(!flag)break;printf("\tto right");printf("\n");


	}	
/*printf("\ntime:%f second(s)",((double)clock()/CLOCKS_PER_SEC));*/
getch();return 0;
}
