#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define N 7
/** Check whether grid[i][j] is valid in the grid */
int isValid1(int row,int column, int (*gr)[N][N])
{
	int i;
	int j;
	for(i = 0; i < row; i ++)if((*gr)[i][column] == (*gr)[row][column])
		{
			return 0;
		}
	for(j = 0; j < column; j ++)if((*gr)[row][j] == (*gr)[row][column])
		{
			return 0;
		}
	return 1; // The current value at grid[row][column] is valid
}
/** Print the values in the grid */
void printGrid(int (*g)[N][N])
{
	int i;
	int j;
	printf("\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ",(*g)[i][j]);
		printf("\n");
	}
}
/** Search for a solution */
int search(int (*gr)[N][N])
{
	int i;
	int j;
	i = 1;
	j = 1;
	int countSoluttion = 0;
	while (1)
	{

		if ((*gr)[i][j] == 0)
			(*gr)[i][j] = 1; // Fill the free cell with number 1

		if (isValid1(i, j, gr))
		{
			if ( i == N-1 && j == N-1)   // No more free cells
			{
				// A solution is found
				countSoluttion ++;
				//printGrid(gr);
				// Fill the free cell with the next possible value
				(*gr)[i][j] = (*gr)[i][j] + 1;
			}
			else   // Move to the next free cell
			{
				if(j<N-1)j++;
				else
				{
					j = 1;
					i ++;
				}
			}
		}
		else if ((*gr)[i][j] < N)
		{
			// Fill the free cell with the next possible value
			(*gr)[i][j] = (*gr)[i][j] + 1;
		}
		else
		{
			// free cell grid[i][j] is 9, backtrack
			while ((*gr)[i][j] == N)
			{
				if (i == 1 && j == 1)
				{
					return countSoluttion; // Since the first FreeCell is not valid and now filled with 9,so no possible value
				}
				(*gr)[i][j] = 0; // Reset to free cell
				{
					if(j>1)j--;
					else
					{
						j = N-1;
						i --;
					}
				}; // Backtrack to the preceding free cell
			}

			// Fill the free cell with the next possible value,
			// search continues from this free cell at freeCellIndex
			(*gr)[i][j] = (*gr)[i][j] + 1;
		}
	}
}

int main()
{
// Read a puzzle
	int i,j;
	int grid[N][N];
	int countSoluttion;
	for(i = 0; i < N; i ++)
		for(j = 0; j < N; j ++)
		{
			grid[i][j] = 0;
		}
	for(i = 0; i < N; i ++)
	{
		grid[0][i] = i + 1;
		grid[i][0] = i + 1;
	}
	int (*p)[N][N] = &grid;
	system("cls");
	countSoluttion = search(p);
	printf("\n%d",countSoluttion);
	printf("\ntime:%f second(s)",((double)clock()/CLOCKS_PER_SEC));
	return 0;
}