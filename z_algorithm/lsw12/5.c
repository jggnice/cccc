#include"stdio.h"
#include"stdlib.h"
#define n 100
#define maxv 9
#define inf 10001
typedef struct
{
	int key;
	int other;
} rectype;
rectype R[n];
int xx = 0;
FILE *fp2;
int arcs[n][n];
int path[n][n], A[n][n];
void printA(int A[][n])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%6d", A[i][j]);
		printf("\n");
	}
}
void list_create(FILE *fp, int *st1, int *st2)
{

	int i;
	int j;
	int k;
	int line_count;
	int startpoint;
	int endpointcount;
	int endpoint;
	int pp1;
	int pp2;

	fscanf(fp, "%d", st1);
	fscanf(fp, "%d", st2);
	fscanf(fp, "%d", &line_count);
	for (i = 0; i < line_count; i++)
	{
		int flag1 = 0;

		fscanf(fp, "%d", &startpoint);

		for(k =0; k < n; k ++)

		{
			if(R[k].key == startpoint)
			{
				pp1 = k;
				flag1 = 1;
				break;
			}

		}
		if(!flag1)
		{
			R[xx].key = startpoint;
			pp1 = xx;
			xx = xx +1;
		}
		fscanf(fp, "%d", &endpointcount);

		for(j = 0 ; j < endpointcount; j++)
		{
			fscanf(fp, "%d", &endpoint);
			//printf("->\n%d",endpoint);
			flag1 = 0;
			for(k =0; k < n; k ++)

			{
				if(R[k].key == endpoint)
				{
					pp2 = k;
					flag1 = 1;
				}

			}
			if(!flag1)
			{
				R[xx].key = endpoint;

				pp2 = xx;
				xx = xx + 1;
			}

			arcs[pp1][pp2] = 1;
			arcs[pp2][pp1] = 1;
			//printf("\n%d,%d",startpoint,endpoint);

		}

	}
}
void FLOYD(void)
{
	int i, j, k, bridge;
	int ii;
	int jj;
	printf("\nFLOYD:\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (arcs[i][j] != maxv)
			{
				/** Modify path */path[i][j] = j + 1;
//each column
			}
			else
			{
				path[i][j] = 0;
			}
			A[i][j] = arcs[i][j];
			/** simply copy */
		}
	//printf("A_0:\n");
	//printA(A);
	//printf("path_0:\n");
	//printA(path);
	for(ii = 0; ii< xx; ii++)
	{
		for(jj=0; jj<xx; jj++)
		{
			printf("%d ",A[ii][jj]);
		}
		printf("\n");
	}
	{
		for (k = 0; k < n; k++)
		{
			/** try point k to make a closer bridge */
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					/** if bridge is closer */
					if (A[i][j] > A[i][k] + A[k][j])
					{
						/** update distance */
						A[i][j] = A[i][k] + A[k][j];
						/** update path to bridge */
						/** Modify path */
						path[i][j] = k + 1;
					}
				}
			}
			/** point k was already tried */
			//printf("\nA_%d:\n",k+1);
			//printA(A);
			//printf("\npath_%d\n",k+1);
			//printA(path);
printf("\n%d\n",k);
			for(ii = 0; ii< xx; ii++)
	{
		for(jj=0; jj<xx; jj++)
		{
			printf("%d ",path[ii][jj]);
		}
		printf("\n");
	}
			
		}
	}
	/** All n points was already tried */
	/** All path possibility was clear */
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			fprintf(fp2, "%d\t", A[i][j]);
			bridge = path[i][j];
			/** Whether if possible */
			if (!bridge)
			{
				;
//fprintf(fp2, "%d to %d no path\n", i + 1, j + 1);
			}
			else
			{
				/**definitly possible (i+1) to (j+1) */
				fprintf(fp2, "%d", i + 1);
				/** loop to destiny (j+1) confidently */
				while (bridge != j + 1)
				{
					fprintf(fp2, "-->%d", bridge);
					bridge = path[bridge - 1][j];
				}
				fprintf(fp2, "-->%d\n", j + 1);
			}
		}
}/*FLOYD*/
int main(int argc, char** argv)
{
	FILE *fp1;
	int ii;
	int jj;
	int k;
	int st1, st2;
	int bridge;

//*********************checkblock***********************************
//check parameters
	if (argc != 3)
	{
		printf("\nusage:\n a.exe input.txt output.txt\n");
		system("pause");
		return 0;
	}
	if ((fp1 = fopen(argv[1], "rt")) == NULL)
	{
		printf("Can't open file.\n");
		system("pause");
		exit (EXIT_FAILURE);
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL)
	{
		printf("Can't open file.\n");
		system("pause");
		exit (EXIT_FAILURE);
	}
	//printf("%s\n%s", argv[0], argv[1]);
//*********************checkblock***********************************
	for (ii = 0; ii < n; ii++)
		for (jj = 0; jj < n; jj++)
		{
			if (ii == jj)
				arcs[ii][jj] = 0;
			else
				arcs[ii][jj] = maxv;
		}
	list_create(fp1, &st1, &st2);
	/* for(k =0; k < xx; k ++)
	{printf("\n%d",R[k].key);} */
	//printf("\npoints are :%d,%d",st1,st2);

	int flag1 = 0;
	for(k =0; k < n; k ++)

	{
		if(R[k].key == st1)
		{
			st1 = k;
			flag1 = 1;
			break;
		}

	}
	flag1 = 0;
	for(k =0; k < n; k ++)

	{
		if(R[k].key == st2)
		{
			st2 = k;
			flag1 = 1;
			break;
		}

	}
for(ii =0;ii< xx;ii++)
{
	printf("\n%d",R[ii].key);
}
	FLOYD();
	/*********slightly modified************/
	printf( "%d\n",A[st2][st1]);
	bridge = path[st2][st1];
	/** Whether if possible */
	if (!bridge)
	{
		;
//fprintf(fp2, "%d to %d no path\n", st1 , st2 );
	}
	else
	{
		/**definitly possible (i+1) to (j+1) */
		printf( "%d", R[st2].key );
		/** loop to destiny (j+1) confidently */
		while (bridge != st1 + 1)
		{
			printf("-->%d", R[bridge - 1].key);
			bridge = path[bridge - 1][st1];
		}
		printf( "-->%d\n", R[st1] );
	}

	/*********slightly modified************/
	fclose(fp1);
	fclose(fp2);
}
