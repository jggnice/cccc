#include"stdio.h"
#include"stdlib.h"
#define n 1000
#define maxv 10000
#define inf 10001
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
	int point_count;
	int edge_count;
	int pp1, pp2;
	int pp_length;
	char str[] = "hkh";
	fscanf(fp, "%d", &point_count);
	fscanf(fp, "%d", &edge_count);
	fscanf(fp, "%d", st1);
	fscanf(fp, "%d", st2);
	for (i = 0; i < edge_count; i++)
	{
		fscanf(fp, "%d", &pp1);
		fscanf(fp, "%d", &pp2);
		fscanf(fp, "%d", &pp_length);
		arcs[pp1][pp2] = pp_length;
		arcs[pp2][pp1] = pp_length;
	}
}
void FLOYD(void)
{
	int i, j, k, bridge;
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
				fprintf(fp2, "%d to %d no path\n", i + 1, j + 1);
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
	printf("%s\n%s", argv[0], argv[1]);
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
	FLOYD();
	/*********slightly modified************/
	printf( "%d\n",A[st1][st2]);
	bridge = path[st1][st2];
	/** Whether if possible */
	if (!bridge)
		fprintf(fp2, "%d to %d no path\n", st1 , st2 );
	else
	{
		/**definitly possible (i+1) to (j+1) */
		printf( "%d", st1 );
		/** loop to destiny (j+1) confidently */
		while (bridge != st2 + 1)
		{
			printf("-->%d", bridge - 1);
			bridge = path[bridge - 1][st2];
		}
		printf( "-->%d\n", st2 );
	}
	/*********slightly modified************/
	fclose(fp1);
	fclose(fp2);
	printf("\n%s", argv[2]);
}
