#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::vector;
using std::string;

bool getValues(vector<long long> &vec);
long long calPoly(const vector<long long> &coefs, long long x);

int main()
{
	vector<long long> coefs;
	vector<long long> values;

	while( getValues(coefs) && !coefs.empty() &&
		   getValues(values) && !values.empty() )
	{
		for(size_t i = 0; i < values.size(); ++i)
		{
			long long result = calPoly(coefs, values[i]);

			if(i!=0) printf(" ");

			printf("%lld", result);
		}
		printf("\n");
		
		coefs.clear();
		values.clear();
	}
}

bool getValues(vector<long long> &vec)
{
	// read line into a string, including newline
	string line;
	if( !std::getline(std::cin, line) )
		return false;

	// split line into coefficients
	std::istringstream iss(line);
	string s;
	while( std::getline(iss, s, ' ') )
	{
		long long i = atoll(s.c_str());

		vec.push_back(i);
	}

	return true;
}

long long calPoly(const vector<long long> &coefs, long long x)
{
	long long result = 0;

	result = coefs[0];
	for(size_t i = 1; i < coefs.size(); ++i)
	{
		result = (result * x) + coefs[i];
	}

	return result;
}