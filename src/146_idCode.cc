#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define MAX 50
#define END '#'

bool getSuccessor(char *code, char *successor);
bool next(char *code, int beg, int end, char *successor);

int main()
{
	char code[MAX+1] = {0};
	while( gets(code) != NULL && code[0] != END )
	{
		char successor[MAX+1] = {0};
		bool hasSuccessor = getSuccessor(code, successor);

		if(hasSuccessor)
			printf("%s\n", successor);
		else
			printf("No Successor\n");

	}
	return 0;
}

bool getSuccessor(char *code, char *successor)
{
	bool result = false;

	int len = strlen(code);
	for(int i = len-2; i >= 0; --i)
	{
		if( next(code, i, len, successor) )
		{
			for(int j = 0; j < i; ++j)
				successor[j] = code[j];

			successor[len] = '\0';
			result = true;
			break;
		}
	}

	return result;
}

bool next(char *code, int beg, int end, char *successor)
{
	int bigIdx = beg;
	char bigChar = 'z' + 1;
	for(int i = beg + 1; i < end; ++i )
	{
		if( code[i] > code[beg] && code[i] < bigChar )
		{
			bigIdx = i;
			bigChar = code[i];
		}
	}

	if(bigIdx == beg) return false;

	successor[beg] = bigChar;

	char *array = (char *)malloc( end - beg - 1 );
	for(int i = beg, j = 0; i < end; ++i)
		if( i != bigIdx)
			array[j++] = code[i];

	std::sort(array, array + end - beg - 1);

	for(int i = 0, j = beg+1; i < end-beg-1; ++i, ++j)
		successor[j] = array[i];

	return true;
}