#include <stdio.h>


int main()
{
	unsigned long long int hashmat = 0, opponent = 0;
	
	while( scanf("%llu%llu", &hashmat, &opponent) != EOF)
	{
		if(opponent >= hashmat)
			printf("%llu\n", opponent-hashmat);
		else
			printf("%llu\n", hashmat-opponent);
	}

	return 0;
}