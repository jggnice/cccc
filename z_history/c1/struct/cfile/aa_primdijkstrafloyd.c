#include"stdio.h"
#include"stdlib.h"
#define n 5
#define maxv 800
#define inf 1000
typedef struct
{
	int from,to;
	int length;
} edge;
int arcs[n][n]= {{0,10,maxv,30,100},{maxv,0,50,maxv,maxv},{maxv,maxv,0,maxv,10},{maxv,maxv,20,0,60},{maxv,maxv,maxv,maxv,0}}; /*邻接矩阵*/
void PRIM(void)
{
	edge E3[n-1];/*边集合*/
	/*从第一个顶点出发构造最小生成树于T中*/
	int j,k,m,v;
	int	min;
	int d;
	edge e;
	for(j=1; j<n; j++)
	{
		E3[j-1].from=1;/*序号1*/
		E3[j-1].to=j+1;/*序号2..n*/
		E3[j-1].length=arcs[0][j];
	}
	for(k=0; k<n-1; k++)
	{
		min=maxv;/*总是有比maxv小的边*/
		for(j=k; j<n-1; j++)
			if(E3[j].length<min)
			{
				min=E3[j].length;
				m=j;
			}
		/*把T[m]换到前面*/
		e=E3[m];
		E3[m]=E3[k];
		E3[k]=e;
		v=E3[k].to;/*新的点*/
		/*调整边*/
		for(j=k+1; j<n-1; j++)
		{
			d=arcs[v-1][E3[j].to-1];
			if(d<E3[j].length)
			{
				E3[j].length=d;
				E3[j].from=v;
			}
		}
	}
	printf("PRIM:\n");
	for(j=1; j<n; j++)
	{
		printf("(%d,%d)|",E3[j-1].from,E3[j-1].to);
	}
}/*PRIM*/
void printP(int *A)
{
	int i;
	for(i=0; i<n; i++)
		printf(" %d",A[i]);
}
void printR(int *A)
{
	int i;
	for(i=0; i<n; i++)
		if(A[i])printf("%d",i+1);
}

void Dijkstra(int v)
{
	/*v是出发点，求单源最短路径*/
	int D[n];/*距离值*/
	int R[n];/*红点集合*/
	int P[n];/*可以记录一个森林：只要记住父节点下标即可，森林的第一个节点为0*/
	int i,j,k=0,v1,pre;
	int min;
	v1=v-1;
	for(i=0; i<n; i++)
	{
		D[i]=arcs[v1][i];
		if(D[i]!=maxv)P[i]=v;
		else P[i]=0;
	}
	P[v1]=0;
	for(i=0; i<n; i++)R[i]=0; /*红点集合*/
	R[v1]=1;
	D[v1]=0;
	printf("\nDijkstra:\n");
	printf("循环\t红点集 ");
	printf("|k+1|\t D[]\t\tP[]");
	printf("\n");
	printf("初始化\t{");
	printR(R);
	printf("}\t|-|");
	printP(D);
	printf("|");
	printP(P);
	printf("\n");
	for(i=0; i<n-1; i++)
	{
		min=inf;
		for(j=0; j<n; j++)
			if((!R[j])&&(D[j]<min))
			{
				min=D[j];
				k=j;
			}
		R[k]=1;/*新红点*/
		for(j=0; j<n; j++)
			/*D[k]新红点本有距离v的值*/
			/*D[j]待调整的距离值*/
			if((!R[j])&&(D[j]>D[k]+arcs[k][j]))
			{
				D[j]=D[k]+arcs[k][j];
				P[j]=k+1;/*P中是序号*/
			}
		printf("%d\t{",i+1);
		printR(R);
		printf("}\t|%d|",k+1);
		printP(D);
		printf("|");
		printP(P);
		printf("\n");
	}/*所有顶点完成*/


	printf("P[]:\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t%d ",D[i],i+1);
		pre=P[i];/*i的父节点*/
		while(pre!=0)
		{
			printf("<--%d",pre);
			pre=P[pre-1];/*找父节点*/
		}
		printf("\n");

	}
}
void printA(int A[][n])
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%5d",A[i][j]);
		printf("\n");
	}
}
void FLOYD(void)
{
	int path[n][n],A[n][n];
	int i,j,k,bridge;
	printf("\nFLOYD:\n");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			if(arcs[i][j]!=maxv)
			{
				path[i][j]=j+1;
//each column
			}
			else
			{
				path[i][j]=0;
			}
			A[i][j]=arcs[i][j];
			/** simply copy */
		}
	printf("A_0:\n");
	printA(A);
	printf("path_0:\n");
	printA(path);
	{
		for(k=0; k<n; k++)
		{
			/** try point k to make a closer bridge */
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					/** if bridge is closer */
					if(A[i][j]>A[i][k]+A[k][j])
					{
						/** update distance */
						A[i][j]=A[i][k]+A[k][j];
						/** update path to bridge */
						path[i][j]=k + 1;
					}
				}
			}
			/** point k was already tried */
			printf("\nA_%d:\n",k+1);
			printA(A);
			printf("\npath_%d\n",k+1);
			printA(path);
		}
	}
	/** All n points was already tried */
	/** All path possibility was clear */
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			printf("%d\t",A[i][j]);
			bridge=path[i][j];
			/** Whether if possible */
			if(!bridge)printf("%d to %d no path\n",i+1,j+1);
			else
			{
				/**definitly possible (i+1) to (j+1) */
				printf("%d",i+1);
				/** loop to destiny (j+1) confidently */
				while(bridge!=j+1)
				{
					printf("-->%d",bridge);
					bridge=path[bridge - 1 ][j];
				}
				printf("-->%d\n",j+1);
			}
		}
}/*FLOYD*/
main()
{
	//PRIM();
	//printf("\n");Dijkstra(4);
	FLOYD();
	getch();
}
