#include <stdio.h>
#include <math.h>

#define COUNT 8

int a[COUNT] = {0};

void queen(int row);
void printQueen();
void clearRow(int row);
bool canPlace(int row, int col);
void place(int row, int col);

int main()
{
	queen(0);
}

void queen(int row)
{
	if(row == COUNT)
		printQueen();
	else
	{

		for(int col = 0; col < COUNT; ++col)
		{
			if( canPlace(row, col) )
			{
				place(row, col);

				queen(row+1);
			}
		}
	}

}

void printQueen()
{
	for(int i = 0; i < COUNT; ++i)
		printf("%d\t", a[i]);

	printf("\n");
}

bool canPlace(int row, int col)
{
	// printf("canPlace(%d, %d)", row, col);

	for(int i = 0; i < row; ++i)
	{
		if(a[i] == col || (row - i) == fabs(double(a[i] - col)) )
			return false;
	}

	return true;
}

void place(int row, int col)
{
	a[row] = col;
}