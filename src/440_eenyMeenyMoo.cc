#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARGET 1

int work(int n);
bool isLastOne(int n, int m);

int main()
{
	int n;

	while(scanf("%d", &n) != EOF && n != 0)
	{
		int m = work(n);
		printf("%d\n", m);
	}

	return 0;
}

int work(int n)
{
	int m = 1;
	
	while( !isLastOne(n, m) )
		++m;

	return m;
}

bool isLastOne(int n, int m)
{
	char *cutted = (char *)malloc(n * sizeof(char));
	memset(cutted, 0, n);

	int now = 0;
	cutted[now] = 1;

	for(int i = 1; i < n; ++i)  // remain n-1 city to cut off
	{
		for(int j = 0; j < m; ++j) // gap is m
		{
			while( cutted[ (++now)%n ] == 1); // if next city is already cutted, process next
		}

		// cut off
		now %= n;
		cutted[now] = 1;

		if(now == TARGET && i < (n-1)) // target city is cutted before last
			return false;
	}

	return true;
}