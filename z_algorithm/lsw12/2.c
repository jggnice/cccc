#include"stdio.h"
#include"stdlib.h"
typedef struct {int key;char other;}rectype;

void swap(rectype *A,rectype *B)
{
 rectype temp;
 temp=*A;*A=*B;*B=temp;
}
int partition(rectype *A,int l,int h)
{
    int i,j,mid;rectype temp;

    i=l;j=h;mid=(l+h)/2;

    if(A[l].key>A[h].key)swap(&A[l],&A[h]);
    if(A[l].key<A[mid].key)swap(&A[l],&A[mid]);
    if(A[l].key>A[h].key)swap(&A[l],&A[h]);

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
}
int main(int argc, char** argv)
{
	FILE *fp1;

int newone;
int count;
int i;
//*********************checkblock***********************************
//check parameters
	if (argc != 2)
	{
		printf("\nusage:\n a.exe input.txt\n");
		system("pause");
		return 0;
	}
	if ((fp1 = fopen(argv[1], "rt")) == NULL)
	{
		printf("Can't open file.\n");
		system("pause");
		exit (EXIT_FAILURE);
	}
//*********************checkblock***********************************
fscanf(fp1,"%d",&count);
rectype R[count];
for(i=0;i<count;i++)
{
	fscanf(fp1,"%d",&newone);
	R[i].key = newone;
}
Quicksort(R,0,count-1);
	fclose(fp1);
for(i=count-1;i>=0;i--)
{
	printf("%d\n", R[i].key);
}
exit(0);
}