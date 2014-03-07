#include <stdio.h>
#include <string>

#define LEN 13

void hexToBinary(int hex, char *bin);

int main()
{
	unsigned N;
	scanf("%u", &N);

	for(unsigned i = 0; i < N; ++i)
	{
		int hex1, hex2;
		char op;
		unsigned result = 0;
		char bin1[LEN+1], bin2[LEN+1];
		bin1[LEN] = bin2[LEN] = '\0';

		scanf("%x %c %x", &hex1, &op, &hex2);

		switch(op)
		{
		case '+':
			result = hex1 + hex2;
			break;
		case '-':
			result = hex1 - hex2;
			break;
		}

		hexToBinary(hex1, bin1);
		hexToBinary(hex2, bin2);

		printf("%s %c %s = %u\n", bin1, op, bin2, result);
	}

	return 0;
}

void hexToBinary(int hex, char *bin)
{
	int i = LEN-1;
	while(hex != 0)
	{
		bin[i--] = '0' + (hex%2);
		hex >>= 1; 
	}

	while(i >= 0) bin[i--] = '0';
}