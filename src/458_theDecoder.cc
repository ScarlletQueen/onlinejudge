#include <stdio.h>

int main()
{
	int c;
	while( (c = getchar()) != EOF )
	{
		if(c != '\n')
			putchar(c-7);
		else
			putchar('\n');
	}
}