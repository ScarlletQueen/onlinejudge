#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool isJolly(int n);

int main()
{
	int n;
	while( scanf("%d", &n) != EOF )
	{
		if( isJolly(n) )
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
}

bool isJolly(int n)
{
	bool result = true;

	char *flags = (char *)malloc(n);
	memset(flags, 0, n);

	int first;
	scanf("%d", &first);

	for(int i =  1; i < n; ++i)
	{
		int second;
		scanf("%d", &second);

		int diff = (int)fabs(double(second-first));

		if(diff >= 1 && diff <= n-1 && flags[diff] == 0)
			flags[diff] = 1;
		
		first = second;
	}

	for(int i = 1; i < n; ++i)
	{
		if(flags[i] == 0)
		{
			result = false;
			break;			
		}
	}

	free(flags);
	return result;
}