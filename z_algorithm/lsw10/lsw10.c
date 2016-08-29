#include<stdio.h>
#include<stdlib.h>
#define N 9
/** Check whether grid[i][j] is valid in the grid */
int isValid1(int i, int j, int (*gr)[N][N])
{
	// Check whether grid[i][j] is valid at the i's row
	int column;
	int row ;
	int col;
	for (column = 0; column < N; column++)
		if (column != j && (*gr)[i][column] == (*gr)[i][j])
			return 0;

	// Check whether grid[i][j] is valid at the j's column
	for (row = 0; row < N; row++)
		if (row != i && (*gr)[row][j] == (*gr)[i][j])
			return 0;

	// Check whether grid[i][j] is valid in the 3 by 3 box
	for (row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
		for (col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
			if (row != i && col != j && (*gr)[row][col] == (*gr)[i][j])
				return 0;

	return 1; // The current value at grid[i][j] is valid
}

/** Check whether the fixed cells are valid in the grid */
int isValid(int (*gr)[N][N])
{
	int i ;
	int j ;
	for (i = 0; i < N; i++)
		for ( j = 0; j < N; j++)
		{
			if ((*gr)[i][j] < 0 || (*gr)[i][j] > N ||((*gr)[i][j] != 0 && !isValid1(i, j, gr)))
				return 0;
		}

	return 1; // The fixed cells are valid
}
/** Print the values in the grid */
void printGrid(int (*g)[N][N])
{
	int i;
	int j;
	printf("\n");
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%d ",(*g)[i][j]);
		printf("\n");
	}
}
int countCell(int (*g)[N][N])
{
	// Determine the number of free cells
	int FreeCells;
	FreeCells = 0;
	int i;
	int j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if ((*g)[i][j] == 0)
			{
				(FreeCells)++;
			}
	return FreeCells;
}
/** Obtain a list of free cells from the puzzle */
void getFreeCellList(int (*g)[N][N],int (*freeCellList)[2])
{
	//warning: function returns address of local variable
	int i;
	int j;
	int count = 0;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if ((*g)[i][j] == 0)
			{
				freeCellList[count][0] = i;
				freeCellList[count++][1] = j;
			}
}
/** Search for a solution */
int search(int (*gr)[N][N])
{
	int i;
	int j;
	int numberOfFreeCells = countCell(gr);
	int freeCellList[numberOfFreeCells][2];
	/**high*/
	getFreeCellList(gr,freeCellList); // Free cells
	/**high*/
	if (numberOfFreeCells == 0)
	{
		return 1; // "No free cells");
	}
	int freeCellIndex = 0; // Start from the first free cell
	while (1)
	{
		/**high*/
		i = freeCellList[freeCellIndex][0];
		j = freeCellList[freeCellIndex][1];
		/**high*/
		if ((*gr)[i][j] == 0)
			(*gr)[i][j] = 1; // Fill the free cell with number 1

		if (isValid1(i, j, gr))
		{
			if (freeCellIndex + 1 == numberOfFreeCells)   // No more free cells
			{
				// A solution is found
				printGrid(gr);
				while ((*gr)[i][j] == 9)
			{
				if (freeCellIndex == 0)
				{
					printf("search end");
					return 0; // Since the first FreeCell is not valid and now filled with 9,so no possible value
				}
				(*gr)[i][j] = 0; // Reset to free cell
				freeCellIndex--; // Backtrack to the preceding free cell
				i = freeCellList[freeCellIndex][0];
				j = freeCellList[freeCellIndex][1];
			}
				// Fill the free cell with the next possible value
				(*gr)[i][j] = (*gr)[i][j] + 1;
			}
			else   // Move to the next free cell
			{
				freeCellIndex++;
			}
		}
		else if ((*gr)[i][j] < 9)
		{
			// Fill the free cell with the next possible value
			(*gr)[i][j] = (*gr)[i][j] + 1;
		}
		else
		{
			// free cell grid[i][j] is 9, backtrack
			while ((*gr)[i][j] == 9)
			{
				if (freeCellIndex == 0)
				{
					printf("search end");
					return 0; // Since the first FreeCell is not valid and now filled with 9,so no possible value
				}
				(*gr)[i][j] = 0; // Reset to free cell
				freeCellIndex--; // Backtrack to the preceding free cell
				i = freeCellList[freeCellIndex][0];
				j = freeCellList[freeCellIndex][1];
			}

			// Fill the free cell with the next possible value,
			// search continues from this free cell at freeCellIndex
			(*gr)[i][j] = (*gr)[i][j] + 1;
		}
	}
}

int main()
{
// Read a Sudoku puzzle
	/*
int grid[N][N]=
	{
		{0,0,0,0,0,0,0,0,2},
		{0,0,0,4,7,0,0,0,0},
		{0,0,3,0,0,0,1,0,6},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,5,0,0,4,9,0},
		{0,0,2,0,0,6,0,0,0},
		{9,0,0,7,0,0,0,0,0},
		{0,0,0,0,0,1,3,0,0},
		{4,5,0,0,0,0,0,7,0}
	};*/
	/*
int grid[N][N] =
	{
		{0,0,5,0,0,3,0,0,0},
		{6,4,0,0,8,0,0,5,2},
		{2,0,0,6,4,0,7,0,1},
		{0,7,0,5,0,0,9,6,4},
		{0,8,0,0,0,0,0,3,0},
		{1,5,4,0,0,9,0,7,0},
		{8,0,3,0,5,7,0,0,9},
		{4,9,0,0,3,0,0,2,7},
		{0,0,0,1,0,0,6,0,0}
	};*/
	/* int grid[N][N] =
	{
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	}; */
	int grid[N][N] =
	{
		{1, 2, 3, 0, 0, 0, 0, 0, 0},
		{4, 5, 6, 0, 0, 0, 0, 0, 0},
		{7, 8, 9, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 2, 3, 0, 0, 0},
		{0, 0, 0, 4, 5, 6, 0, 0, 0},
		{0, 0, 0, 7, 8, 9, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 2, 3},
		{0, 0, 0, 0, 0, 0, 4, 5, 6},
		{0, 0, 0, 0, 0, 0, 7, 8, 9}
	};
	int (*p)[N][N] = &grid;
	system("cls");
	if (!isValid(p))
		printf("Invalid input");
	else
	{
		search(p);
	}
	return 0;
}