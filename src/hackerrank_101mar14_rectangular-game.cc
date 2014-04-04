#include <stdio.h>

int main()
{
	int N = 0;
	scanf("%d", &N);

	unsigned long long minRow = 10^6, minCol = 10^6;
	for( int i = 0 ; i < N; ++i )
	{
		unsigned long long a = 0, b = 0;
		scanf("%llu %llu", &a, &b);
		if(minRow > a) minRow = a;
		if(minCol > b) minCol = b;
	}

	unsigned long long result = minRow * minCol;
	printf("%llu\n", result );
	return 0;
}