#include <stdio.h>
#include <stdlib.h>

void ProcessMatrix(unsigned row, unsigned col, unsigned field);

int main()
{
	unsigned int field = 1;
	unsigned int n, m;
	bool first = true;

	while( scanf("%u %u", &n, &m) != EOF )
	{
		if( 0==n && 0==m ) break;

		if(first) first = false;
		else printf("\n");

		ProcessMatrix(n, m, field++);
	}

	return 0;
}

void ProcessMatrix(unsigned row, unsigned col, unsigned field)
{
	// init matrix
	unsigned int **array = (unsigned **)malloc((row+2) * sizeof(unsigned*));
	for(unsigned int i = 0; i < row+2; ++i)
		array[i] = (unsigned int *)malloc((col+2) * sizeof(unsigned *));

	for(unsigned int i=0; i < col+2; ++i)
		array[0][i] = array[row+1][i] = 0;
	for(unsigned int i=1; i < row+1; ++i)
		array[i][0] = array[i][col+1] = 0;

	// read matrix
	for(unsigned int i = 0; i < row; ++i)
	{
		for(unsigned int j = 0; j < col; )
		{
			unsigned int c = getchar();
			//printf("%c %d", c, c);

			switch(c)
			{
				case '*':
					array[i+1][j+1] = 1;
					++j;
					break;
				case '.':
					array[i+1][j+1] = 0;
					++j;
					break;
			}
		}
	}

	//print
	printf("Field #%u:\n", field++);
	for(unsigned int i = 1; i < row+1; ++i)
	{
		for(unsigned int j = 1; j < col+1; ++j)
		{
			if(array[i][j] == 1) 
				printf("*");
			else
			{
				unsigned int number = array[i-1][j-1] + array[i-1][j] + array[i-1][j+1] +
						 array[i][j-1]   + array[i][j]   + array[i][j+1] + 
						 array[i+1][j-1] + array[i+1][j] + array[i+1][j+1];
				printf("%d", number);
			}
		}

		printf("\n");
	}
	//printf("\n");
}