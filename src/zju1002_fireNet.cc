#include <stdio.h>
#include <stdlib.h>

#define STREET '.'
#define WALL 'X'
#define BLOCK_HOUSE 'O'

void fireNet(char *city, int n, int cur, int *maxHouse);
void countBlockHouse(char *city, int n, int *maxHouse);
bool canPlace(char *city, int n, int cur);
void place(char *city, int cur);
void remove(char *city, int cur);

int main()
{
	int n;
	while( scanf("%d", &n) != EOF && n != 0 )
	{
		// init city from stdin
		char *city = (char *)malloc(n*n);
		for(int i = 0; i < n*n;)
		{
			char ch;
			scanf("%c",&ch);
			if(ch == WALL || ch == STREET)
				city[i++] = ch;			
		}

		int maxHouse = 0;
		fireNet(city, n, 0, &maxHouse);

		printf("%d\n", maxHouse);
	}

	return 0;
}

void fireNet(char *city, int n, int cur, int *maxHouse)
{
	if(cur == n*n)
		countBlockHouse(city, n, maxHouse);
	else
	{
		if( canPlace(city, n, cur) )
		{
			place(city, cur);	

			fireNet(city, n, cur+1, maxHouse);

			remove(city, cur);

			fireNet(city, n, cur+1, maxHouse);	
		}
		else
		{
			fireNet(city, n, cur+1, maxHouse);
		}
	}
}

void countBlockHouse(char *city, int n, int *maxHouse)
{
	int count = 0;
	int total = n*n;
	for(int i = 0; i < total; ++i)
	{
		if(city[i] == BLOCK_HOUSE)
			++count;
	}

	*maxHouse = count > *maxHouse ? count : *maxHouse;
}

bool canPlace(char *city, int n, int cur)
{
	if(city[cur] == WALL) return false;

	int row = cur / n;
	int col = cur % n;

	for(int i = col-1; i >= 0; --i)
	{
		if(city[row*n + i] == WALL)
			break;

		if(city[row*n + i] == BLOCK_HOUSE)
			return false;
	}

	for(int i = row-1; i >=0; --i)
	{
		if(city[i*n + col] == WALL)
			break;

		if(city[i*n + col] == BLOCK_HOUSE)
			return false;
	}

	return true;
}

void place(char *city, int cur)
{
	city[cur] = BLOCK_HOUSE;
}

void remove(char *city, int cur)
{
	city[cur] = STREET;
}