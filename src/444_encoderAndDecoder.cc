#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 240

void Encode(char *message);
void Decode(char *message);

int main()
{
	char message[MAX_LEN+1] = {0};

	while( gets(message) )
	{
		if(message[0] >= '0' && message[0] <= '9') // decode
			Decode(message);
		else
			Encode(message);

	}
	// return 0;
}

/**
 * [encoding message]
 * @param message
 */
void Encode(char *message)
{
	size_t len = strlen(message);
	for(size_t i = 0; i < len; ++i)
	{
		// ascii to string
		char buf[4];
		sprintf(buf, "%d", (int)message[len-1-i]);
		// itoa((int)message[len-1-i], buf, 10);

		// swap the first char and the last one
		size_t last = strlen(buf) - 1;
		char temp = buf[last];
		buf[last] = buf[0];
		buf[0] = temp;

		// output encoded char
		printf("%s", buf);
	}

	printf("\n");
}

void Decode(char *message)
{
	size_t len = strlen(message);
	size_t i = 0;
	while(i < len)
	{
		// get decoded char in buffer 
		char buf[4];
		if(message[len-1-i] == '1')
		{
			buf[0] = '1';
			buf[1] = message[len-1-i-1];
			buf[2] = message[len-1-i-2];
			buf[3] = '\0';

			i += 3;
		}
		else
		{
			buf[0] = message[len-1-i];
			buf[1] = message[len-1-i-1];
			buf[2] = '\0';

			i += 2;
		}

		printf("%c", atoi(buf));
	}

	printf("\n");
}