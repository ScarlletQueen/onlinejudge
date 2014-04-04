// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Clarification:
// What constitutes a word?
// A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
// Yes. However, your reversed string should not contain leading or trailing spaces.
// How about multiple spaces between two words?
// Reduce them to a single space in the reversed string.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        
        trimString(s);

        size_t len = s.size();

        reverse(s, 0, len);

        size_t wordBeg = 0;
        for(size_t i =0; i < len; ++i )
        {
        	if(s[i] == ' ')
        	{
        		reverse(s, wordBeg, i);
        		wordBeg = i+1;
        	}
        }

        reverse(s, wordBeg, len);
    }

    void trimString(string &s){

    	size_t len = s.size();
    	bool inWord = false;
    	size_t i = 0, j=0;

    	for(; i < len; ++i)
    	{
    		if(inWord == false && s[i] ==' ')
    			continue;
    		else
    		{
    			s[j++] = s[i];

    			inWord = s[i] == ' '? false: true;
    		}
    	}

    	if(j > 0 && inWord == false) // end with space
    		--j;

    	s.erase(s.begin() + j, s.end());
    }

    void reverse(string &s, size_t beg, size_t end)
    {
    	while(beg < end)
    	{
    		char tmp = s[beg];
    		s[beg] = s[end-1];
    		s[end-1] = tmp;
    		++beg;
    		--end;
    	}
    }
};

int main()
{
	Solution sln;

	string s = "  gui jie   ";
	sln.reverseWords(s);
	cout << "[" << s<< "]" << endl;

	return 0;
}