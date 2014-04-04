// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.

#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

		if(s.empty()) return true;

		size_t len = s.size();
		
		for(size_t i = 0, j = len-1; i < j;)
		{
			while(i < len && !isalnum(s[i]) ) ++i;
			while(j > i && !isalnum(s[j]) ) --j;

			if(i >= j ) return true;

			int leftChar = tolower(s[i++]);
			int rightChar = tolower(s[j--]);

			if(leftChar != rightChar)
				return false;
		}        
		return true;
    }


};

int main()
{
	Solution sln;

	string s = " a A";
	cout << sln.isPalindrome(s) << endl;

	return 0;
}