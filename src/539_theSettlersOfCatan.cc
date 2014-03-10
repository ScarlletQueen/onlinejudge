#include <stdio.h>
#include <stdlib.h>

#define DEGREE 3

class city;
void Init(city *cities, int n, int m);
void print(city *cities, int n);
int  work(city *cities, int n, int m);

class city
{
public:
	city(int id = -1):_id(id)
	{
		for(int i = 0; i < DEGREE; ++i)
		{
			_neibours[i] = NULL;
			_isChecked[i] = true;			
		}
	}

	~city(){}

	void setId(int id){ _id = id; }
	
	// bugs in here!
	void addNeibour(city *neibour)
	{
		// printf("add neibour curId:%d, neibourId: %d\n", _id, neibour->_id);
		for(int i = 0; i < DEGREE; ++i)
		{
			if(_neibours[i] != NULL && _neibours[i]->_id == neibour->_id )
				return;

			if(_neibours[i] == NULL)
			{
				_neibours[i] = neibour;
				_isChecked[i] = false;
				return;
			}
		}
	}

	int id(){ return _id; }

	int printNeibours()
	{
		printf("cur:%d; neibours: ", _id);
		for(int i = 0; i < DEGREE; ++i)
		{
			if( _neibours[i] != NULL)
				printf("%d:%s;  ", _neibours[i]->id(), _isChecked[i]?"Checked":"Unchecked");
		}
		printf("\n");
	}

	void setIsCheck( int id, bool isCheck )
	{
		for(int i = 0; i < DEGREE; ++i)
		{
			if( _neibours[i] != NULL && _neibours[i]->_id == id )
			{
				if(_isChecked[i] != isCheck)
				{
					_isChecked[i] = isCheck;

					_neibours[i]->setIsCheck(_id, isCheck);
				}

				return;
			}
		}
	}

	void searchLongestRode(int begin, int *currentLength, int *longestRode)
	{
		// printf("search: begin:%d, cur: %d, curLen:%d, longest:%d\n", 
		// 	begin, _id, *currentLength, *longestRode);
		for(int i = 0; i < DEGREE; ++i)
		{
			if(_neibours[i] != NULL && _isChecked[i] == false)
			{
				*currentLength = *currentLength + 1;

				setIsCheck(_neibours[i]->_id, true);

				// printNeibours();

				_neibours[i]->searchLongestRode(_id, currentLength, longestRode);
			}
		}

		if(*currentLength > *longestRode)
			*longestRode = *currentLength;

		if(begin >= 0)
		{
			setIsCheck(begin, false);
			*currentLength = *currentLength - 1;			
		}
	}

private:
	int _id;
	city *_neibours[DEGREE];
	bool _isChecked[DEGREE];
};

int main()
{
	int n, m;
	while( scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0 )
	{
		city *cities = new city[n];
		Init(cities, n, m);
		// print(cities, n);
		// printf("\n");

		int longestRode = work(cities, n, m);
		printf("%d\n", longestRode);

		delete cities;
	}
	return 0;
}

void Init(city *cities, int n, int m)
{
	for(int i = 0; i < n; ++i)
		cities[i].setId(i);

	for(int i = 0; i < m; ++i)
	{
		int beg, end;
		scanf("%d %d", &beg, &end);
		cities[beg].addNeibour(&cities[end]);
		cities[end].addNeibour(&cities[beg]);
	}
}

void print(city *cities, int n)
{
	for(int i = 0; i < n; ++i)
	{
		printf("city: %d\n", cities[i].id());
		cities[i].printNeibours();
	}
}

int work(city *cities, int n, int m)
{
	int result = 0;

	for(int i = 0; i < n; ++i)
	{
		int currentLength = 0, longest = 0;

		cities[i].searchLongestRode(-1, &currentLength, &longest);

		if(longest > result)
			result = longest;

		// printf("\n");
	}

	return result;
}