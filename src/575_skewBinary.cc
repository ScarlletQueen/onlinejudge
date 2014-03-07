#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 32

long skewBinary(char *binary);

int main()
{
	char binary[MAX_LEN] = {0};

	while( gets(binary) != NULL )
	{
		if( strcmp(binary, "0") == 0  )
			break;

		// printf("%s\n", binary);

		long decimal = skewBinary(binary);
		printf("%ld\n", decimal);
	}

	return 0;
}

long skewBinary(char *binary)
{
	long decimal = 0;

	size_t len = strlen(binary);
	for(int i = 0; i < len; ++i)
	{
		if(binary[i] == '1' )
		{
			// printf("binary[%d]=%c\n", i, binary[i]);

			// printf( "len = %d, i = %d\n", len, i );

			decimal += ( (1 << (len-i))- 1 );
			
		}
		else if(binary[i] == '2')
		{
			// printf("binary[%d]=%c\n", i, binary[i]);

			decimal += ( (1 << (len+1-i)) - 2 );
			break;
		}
	}

	return decimal;
}