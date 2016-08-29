#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 5
struct moved{int x,y;}move[8]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};
int mine[N+2][N+2]={0};				//���׵ĵط�
int countmine[N+2][N+2]={0};		//�������׸���
int showsign[N+2][N+2]={0};			//�Ƿ�Ҫ���
int flag=0;							//�˳���־	

//
int countsign(void)
{int a,b,sum=0;
for(a=1;a<N+1;a++)					//������־���
{for(b=1;b<N+1;b++)sum+=showsign[a][b];}
return N*N-sum;}
void printmine(int A[N+2][N+2])		//������־���
{	int a,b;						//������־���
for(a=1;a<N+1;a++)					//������־���
	{for(b=1;b<N+1;b++)printf("%d ",A[a][b]);printf("\n");}
}									//������־���


void shows(void)
{int a,b;system("cls");
	for(a=1;a<N+1;a++)				//������־���
	{for(b=1;b<N+1;b++)				//������־���
		{if(showsign[a][b])printf(" %d ",countmine[a][b]);else printf("[ ]");}
	printf("\n");					//������־���
	}								//������־���
}									//������־���

void showaround(int i,int j)
{	int a,b,v;
	showsign[i][j]=1;
	for(v=0;v<8;v++)
	{a=i+move[v].x;b=j+move[v].y;if(!mine[a][b])showsign[a][b]=1;}
	
}
void select(int i,int j)
{if(mine[i][j]){flag=1;printf("your bomb!");return;}else {showaround(i,j);shows();printf("\n");return;}}
void mymain( void )
{int i=1,j,a,b,v;char ch;
 //��ӡ�����
srand(time(NULL));          //��ʼ�������
while(i<=(int)(2*sqrt(N)))    //��ӡ�����
{a=rand()%(N);
	b=rand()%(N);			//��ӡ�����
	if(!mine[a+1][b+1])
	{mine[a+1][b+1]=1;		//��ӡ�����
	printf("%d%d  ",a+1,b+1);
	i++;					//��ӡ�����
	}						//��ӡ�����
}
 //��ӡ�����
//�������׸���
for(a=1;a<N+1;a++)
{
	for(b=1;b<N+1;b++)					//�������׸���
		for(v=0;v<8;v++)				//�������׸���
		{
			i=a+move[v].x;j=b+move[v].y;//�������׸���
			countmine[a][b]+=mine[i][j];//�������׸���
		}
}										//�������׸���
printf("\n");							
printmine(mine);							//��ӡ����

printf("\n1:input\t2:printmine\t3:show_count\t4:showsign\t$:exit \n");
	while((!flag)&&(countsign()>2*(sqrt(N)))&&(ch=getchar())!='$')
		{
			printf("1:input\t$:exit\tremain %d bombs!\n",(int)(2*sqrt(N)));
			switch(ch)
			{case '1':{printf("input (i,j):");scanf("%d,%d",&i,&j);select(i,j);break;}
			case '2':printmine(mine);break;
			case '3':printmine(countmine);break;
			case '4':printmine(showsign);break;
		}
	}

}


void main(void)
{
	mymain();
	//�������׸���
	if(countsign()<=2*(sqrt(N)))
		printf("congratulations!\nyou success!\nOK!");getch();
}
