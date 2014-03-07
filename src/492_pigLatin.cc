#include <stdio.h>

char VOWELS[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

bool isLetter(char c);
bool isVowel(char c);

int main()
{
	char c;
	bool inWord = false;
	char vowel = 0; 
	
	while( (c = getchar()) != EOF )
	{
		if(inWord == false && isLetter(c) == true )
		{
			inWord = true;

			if( isVowel(c) == false )
				vowel = c;
			else
			{
				putchar(c);
				vowel = 0;
			}
		}
		else if( inWord == true && isLetter(c) == false )
		{
			inWord = false;

			if(vowel != 0) 
			{
				putchar(vowel);
				vowel = 0;
			}

			printf("ay");

			putchar(c);
		}
		else
			putchar(c);
	}

	if(inWord)
	{
		if(vowel != 0) 
		{
			putchar(vowel);
			vowel = 0;
		}

		printf("ay");		
	}


	return 0;
}

bool isLetter(char c)
{
	if( (c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z' ) )
		return true;
	else 
		return false;
}

bool isVowel(char c)
{
	for(int i = 0; i < sizeof(VOWELS)/sizeof(VOWELS[0]); ++i)
		if( c ==  VOWELS[i])
			return true;

	return false;
}