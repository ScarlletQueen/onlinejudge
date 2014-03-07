#include <iostream>

char mirrorMap[][2] = 
{
	{'A','A'}, {'E','3'}, {'H','H'}, {'I','I'}, {'J','L'}, {'L','J'},
	{'M','M'}, {'O','O'}, {'S','2'}, {'T','T'}, {'U','U'}, {'V','V'},
	{'W','W'}, {'X','X'}, {'Y','Y'}, {'Z','5'}, {'1','1'}, {'2','S'},
	{'3','E'}, {'5','Z'}, {'8','8'}
};

int main()
{
	std::cout << sizeof(mirrorMap) << std::endl;
	std::cout << sizeof(mirrorMap[0]) << std::endl;
	std::cout << sizeof(mirrorMap[0][0]) << std::endl;

	return 0;

}