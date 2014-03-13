#include <stdio.h>
#include <stdlib.h>

struct square
{
	square(int row, char col):row(row), col(col){}
	int row;
	char col;
};

bool travel(int p, int q, square *path);
bool search(square cur, int step, int p, int q, bool *visited, square *path);

int main()
{
	unsigned n;
	scanf("%u", &n);
	for(unsigned testCase = 1; testCase <= n; ++testCase)
	{
		int p, q;
		scanf("%d %d", &p, &q);

		square *path = (square *)malloc(p*q*sizeof(square));

		bool success = travel( p, q, path );

		printf("Scenario #%u:\n", testCase);
		if(success)
		{
			for(int i = 0; i < p*q; ++i)
				printf("%c%d", path[i].col, path[i].row+1);
		}
		else
		{
			printf("impossible");
		}
		printf("\n\n");

		free(path);
	}
}

bool travel(int p, int q, square *path)
{
	bool *visited = (bool *)malloc(p*q*sizeof(bool));
	for(int i = 0; i < p*q; ++i)
		visited[i] = false;

	for( int col = 0; col < q; ++col )
	{
		for( int row = 0; row < p; ++row )
		{
			square cur(row, col+'A');
			path[0] = cur;

			visited[row*q + col] = true;

			if( search(cur, 1, p, q, visited, path) )
				return true;
			else
				visited[row*q + col] = false;
		}
	}

	free(visited);
	return false;
}

bool search(square cur, int step, int p, int q, bool *visited, square *path)
{
	if(step == p * q ) return true;

	int rows[8] = { cur.row-1, cur.row+1, cur.row-2, cur.row+2,
					cur.row-2, cur.row+2, cur.row-1, cur.row+1 };
	char cols[8] = { cur.col-2, cur.col-2, cur.col-1, cur.col-1,
					 cur.col+1, cur.col+1, cur.col+2, cur.col+2 };
	for(int i = 0; i < 8; ++i)
	{
		if( rows[i] >= 0 && rows[i] < p && cols[i] >= 'A' && cols[i] < 'A'+q &&
			visited[ rows[i]*q+cols[i]-'A' ] == false)
		{
			visited[ rows[i]*q+cols[i]-'A' ] = true;
			path[step] = square(rows[i], cols[i]);	

			if(search(path[step], step+1, p, q, visited, path))
				return true;
			else
				visited[ rows[i]*q+cols[i]-'A' ] = false;
		}
	}

	return false;
}
