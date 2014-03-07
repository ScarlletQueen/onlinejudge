#include <stdio.h>
#include <stdlib.h>

#define ABSENCE '*'
#define OIL '@'
#define PROCESSED 'X'

int oilDeposits(int m, int n);
void init(int m, int n, char *matrix);
void printMatrix(int m, int n, char *matrix);

int main()
{
	int m, n;
	while( scanf("%d %d\n", &m, &n) != EOF && m != 0 && n != 0 )
	{
		int pockets = oilDeposits(m, n);

		printf("%d\n", pockets);
	}

	return 0;
}

int oilDeposits(int m, int n)
{
	int pockets = 0;

	char *matrix = (char *)malloc(m*n);
	
	init(m, n, matrix);
	
	printMatrix(m, n, matrix);

	free(matrix);
	return pockets;
}

void init(int m, int n, char *matrix)
{
	char *line = (char*)malloc(n+1);
	for(int row = 0; row < m; ++row)
	{
		gets(line);

		for(int col = 0; col < n; ++col)
			matrix[row*n + col] = line[col];
	}
	free(line);
}

void printMatrix(int m, int n, char *matrix)
{
	for(int row = 0; row < m; ++row)
	{
		for(int col = 0; col < n; ++col)
			printf("%c ", matrix[row*n + col]);

		printf("\n");
	}
}