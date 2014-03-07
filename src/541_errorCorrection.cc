#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define CHANGE_BIT 1
#define CORRUPT 2
#define ERROR 3

void errorCorrection(int n);
int isParity(int *matrix, int n, int *changeRow, int *changeCol);
int isParityEx(int *matrix, int n, int *changeRow, int *changeCol);
void printResult(int result, int changeRow, int changeCol);
void PrintMatrix(int *matrix, int n);

int main()
{
	int n;
	while( scanf("%d", &n) != EOF && n != 0 )
	{
		errorCorrection(n);
	}
	return 0;
}

void errorCorrection(int n)
{
	// init matrix
	int *matrix = (int *)malloc( sizeof(int)*n*n );
	if(matrix == NULL) return;

	for( int i = 0; i < n * n; ++i )
		scanf("%d", matrix+i );

	// PrintMatrix(matrix, n);

	// is parity
	int changeRow, changeCol;
	int result = isParityEx(matrix, n, &changeRow, &changeCol);

	// print result
	printResult(result, changeRow, changeCol);

	// free matrix 
	free(matrix);
}

int isParityEx(int *matrix, int n, int *changeRow, int *changeCol)
{
	int result = ERROR;

	int *rowValues = (int *)malloc( sizeof(int)*n );
	int *colValues = (int *)malloc( sizeof(int)*n );
	if(rowValues == NULL || colValues == NULL) 
		return ERROR;
	for(int i = 0; i < n; ++i)
		rowValues[i] = colValues[i] = 0;

	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < n; ++col)
		{
			rowValues[row] += matrix[row*n + col];
			colValues[col] += matrix[row*n + col];
		}
	}

	*changeRow = *changeCol = -1;

	for(int i = 0; i < n; ++i)
	{
		if( rowValues[i] % 2 != 0 )
		{
			if(*changeRow == -1)
				*changeRow = i;
			else
				return CORRUPT;				
		}

		
		if( colValues[i] % 2 != 0 )
		{
			if(*changeCol == -1)
				*changeCol = i;
			else
				return CORRUPT;
		}
	}

	if(*changeRow == -1 && *changeCol == -1 )
		return OK;
	else if( *changeRow >= 0 && *changeCol >= 0 )
		return CHANGE_BIT;
	else 
		return CORRUPT;
}

int isParity(int *matrix, int n, int *changeRow, int *changeCol)
{
	int result = ERROR;
	*changeRow = *changeCol = -1;

	int *rowValues = (int *)malloc( sizeof(int)*n );
	int *colValues = (int *)malloc( sizeof(int)*n );
	if(rowValues == NULL || colValues == NULL) 
		return ERROR;

	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < n; ++col)
		{
			rowValues[row] += matrix[row*n + col];
			colValues[col] += matrix[row*n + col];
		}

		if( rowValues[row] % 2 != 0 )
		{
			if( *changeRow == -1 )
				*changeRow = row;
			else
				return CORRUPT; // more than two odd row, corrupt
		}
	}

	for(int col = 0; col < n; ++col)
	{
		if( colValues[col] % 2 != 0 )
		{
			if(*changeCol == -1)
				*changeCol = col;
			else
				return CORRUPT; // more than two odd col, corrupt
		}
	}

	if(*changeRow == -1 && *changeCol == -1 )
		return OK;
	else if( *changeRow >= 0 && *changeCol >= 0 )
		return CHANGE_BIT;
	else 
		return CORRUPT;
}

void printResult(int result, int changeRow, int changeCol)
{
	switch(result)
	{
	case OK:
		printf("OK\n");
		break;
	case CHANGE_BIT:
		printf("Change bit (%d,%d)\n", changeRow+1, changeCol+1);
		break;
	case CORRUPT:
		printf("Corrupt\n");
		break;
	}
}

void PrintMatrix(int *matrix, int n)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			printf("%d ", matrix[i*n+j]);

		printf("\n");
	}
}