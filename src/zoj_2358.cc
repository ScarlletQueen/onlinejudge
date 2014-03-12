#include <stdio.h>

static const unsigned int fac[] = 
	{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
bool isSumOfFactorials(int n, int beg);

int main()
{
	int n;
	while( scanf("%d", &n) != EOF && n >= 0 )
	{
		if(n == 0)
		{
			printf("NO\n");
		} 
		else
		{
			if(isSumOfFactorials(n, 0))
				printf("YES\n");
			else
				printf("NO\n");			
		}
	}
}

bool isSumOfFactorials(int n, int beg)
{
	if(n == 0) return true;
	if(n < 0) return false;

	for( int i = beg; i < 10; ++i )
	{
		if(isSumOfFactorials(n-fac[i], i+1))
			return true;
	}

	return false;
}
