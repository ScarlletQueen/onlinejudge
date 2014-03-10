#include <stdio.h>
#include <stdlib.h>

#define ABSENCE '*'
#define OIL '@'
#define CHECKED 'X'

int oilDeposits(int M, int N);
void init(int M, int N, char **matrix);
void printMatrix(int M, int N, char **matrix);

// method 1: recursively
int oilDeposits_Recursive(char **matrix, int M, int N);
void searchRecursively(char **matrix, int M, int N, int row, int col);

int main()
{
	int M, N;
	while( scanf("%d %d\n", &M, &N) != EOF && M != 0 && N != 0 )
	{
		int pockets = oilDeposits(M, N);

		printf("%d\n", pockets);
	}

	return 0;
}

int oilDeposits(int M, int N)
{
	char **matrix = (char **)malloc(M * sizeof(char*));
	for(int i = 0; i < M; ++i)
		matrix[i] = (char *)malloc(N*sizeof(char));
	
	init(M, N, matrix);

	// printMatrix(M, N, matrix);
	
	int pockets = oilDeposits_Recursive(matrix, M, N);	

	// for(int i = 0; i < M; ++i)
	// 	free(matrix[i]);
	// free(matrix);

	return pockets;
}

void init(int M, int N, char **matrix)
{
	char *line = (char*)malloc(N+1);
	for(int row = 0; row < M; ++row)
	{
		gets(line);

		for(int col = 0; col < N; ++col)
			matrix[row][col] = line[col];
	}
	free(line);
}

void printMatrix(int M, int N, char **matrix)
{
	for(int row = 0; row < M; ++row)
	{
		for(int col = 0; col < N; ++col)
			printf("%c ", matrix[row][col]);

		printf("\n");
	}
}

int oilDeposits_Recursive(char **matrix, int M, int N)
{	
	int pockets = 0;

	for(int row = 0; row < M; ++row)
	{
		for(int col = 0; col < N; ++col)
		{
			if(matrix[row][col] == OIL) 
			{
				// printf("oilDeposits_Recursive new oil, m[%d][%d]\n", row, col);
				++pockets;

				searchRecursively(matrix, M, N, row, col);
			}
		}
	}

	return pockets;
}

void searchRecursively(char **matrix, int M, int N, int row, int col)
{	
	int rows[8] = {row-1, row-1, row-1, row, row, row+1, row+1, row+1 };
	int cols[8] = {col-1, col, col+1, col-1, col+1, col-1, col, col+1};

	for( int i = 0; i < 8; ++i )
	{
		if( rows[i] >= M || rows[i] < 0 || cols[i] >= N || cols[i] < 0 ) // invalid neibour
			continue;

		if(matrix[rows[i]][cols[i]] == CHECKED)
			continue;

		if(matrix[rows[i]][cols[i]] == ABSENCE)
		{
			matrix[rows[i]][cols[i]] = CHECKED;
			continue;
		}

		// OIL																																																																																																																																																																																																																																																																																																																																																																						`																													
		matrix[rows[i]][cols[i]] = CHECKED;
		searchRecursively(matrix, M, N, rows[i], cols[i]);
	}
}