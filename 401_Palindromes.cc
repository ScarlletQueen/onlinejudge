#include <stdio.h>
#include <iostream>
#include <string>

char mirrorMap[][2] = 
{
	{'A','A'}, {'E','3'}, {'H','H'}, {'I','I'}, {'J','L'}, {'L','J'},
	{'M','M'}, {'O','O'}, {'S','2'}, {'T','T'}, {'U','U'}, {'V','V'},
	{'W','W'}, {'X','X'}, {'Y','Y'}, {'Z','5'}, {'1','1'}, {'2','S'},
	{'3','E'}, {'5','Z'}, {'8','8'}
};

bool getLine(char *str);
bool IsPalindrome(const char *str, size_t len);
bool IsMirrored(const char *str, size_t len);
char getMirroredLetter(char ch);

int main()
{
	std::string str;
	while( std::getline(std::cin, str) && str.length() > 0 )
	{
		bool isPalindrome = IsPalindrome(str.c_str(), str.size());
		bool isMirrored = IsMirrored(str.c_str(), str.size());

		if(!isPalindrome && !isMirrored)
			printf("%s -- is not a palindrome.\n\n", str.c_str());
		else if(isPalindrome && !isMirrored)
			printf("%s -- is a regular palindrome.\n\n", str.c_str());
		else if(!isPalindrome && isMirrored)
			printf("%s -- is a mirrored string.\n\n", str.c_str());
		else			
			printf("%s -- is a mirrored palindrome.\n\n", str.c_str());
	}

	return 0;
}

bool IsPalindrome(const char *str, size_t len)
{
	bool result = true;

	for(size_t i = 0; i < len/2; ++i)
	{
		if( str[i] != str[len-1-i] )
		{
			result = false;
			break;
		}
	}

	return result;
}

bool IsMirrored(const char *str, size_t len)
{
	for(size_t i = 0; i < len/2; ++i)
	{		
		char mirroredletter = getMirroredLetter(str[i]);

		if( mirroredletter == '\0'  || mirroredletter != str[len-1-i] )
			return false;			
	}

	if(len%2 == 1)  // len is odd, check the middle letter
	{
		char mirroredletter = getMirroredLetter(str[len/2]);

		if( mirroredletter == '\0' || mirroredletter != str[len/2] )
			return false;
	}

	return true;
}

char getMirroredLetter(char ch)
{
	char mirroredletter = '\0';

	for(size_t j = 0; j < sizeof(mirrorMap)/sizeof(mirrorMap[0]); ++j)
	{
		if(ch == mirrorMap[j][0])
		{
			mirroredletter = mirrorMap[j][1];
			break;				
		}
	}

	return mirroredletter;
}