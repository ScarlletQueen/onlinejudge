#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

#define ACROSS 'A'
#define DOWN 'D'

// slot 1 & slot 2 crossed.
// if word1 at slot1, word2 at slot2, 
// cross point is word1[idx1] and word2[idx2]
struct CrossPoint
{
	CrossPoint(int i, int j, int idx1, int idx2):slot1(i), slot2(j), idx1(idx1), idx2(idx2){}
	int slot1;
	int slot2;
	int idx1;
	int idx2;
};

struct Slot
{
	Slot(int i, int j, char c):row(i), col(j),direction(c){}
	int row; // Solt begins at [row][col]
	int col; 
	char direction; // slot direction
	vector<CrossPoint> crossPoints; // crossed at these points
};

struct Word
{
	string word;
	int slotIdx; // init as -1
};

class CrossPuzzle
{
public:
	void init(int N);

	void work(int n = 0);

	void getResult(set<string> &result) 
	{ result = unusedWords; }

	void print();

private:
	void calculateJointPoints();

	void addUnusedWord()
	{
		for(size_t i = 0; i < words.size(); ++i)
			if(words[i].slotIdx < 0)
				unusedWords.insert(words[i].word);
	}

	bool canPlace(int slotIdx, int wordIdx);

	void place(int s, int w){ words[w].slotIdx = s; }

	void remove(int s, int w){ words[w].slotIdx = -1; }

	vector<Slot> slots;
	vector<Word> words;
	set<string> unusedWords;
};

void CrossPuzzle::print()
{
	for(size_t i = 0; i < slots.size(); ++i)
	{
		printf( "slot[%d]: %d %d %c\n", i, slots[i].row, slots[i].col, slots[i].direction );

		for(size_t j = 0; j < slots[i].crossPoints.size(); ++j)
			printf(" slot[%d].%d cross slot[%d].%d\n", 
				slots[i].crossPoints[j].slot1, 
				slots[i].crossPoints[j].idx1, 
				slots[i].crossPoints[j].slot2,
				slots[i].crossPoints[j].idx2 );
		
		printf("\n\n");
	}
}

void CrossPuzzle::init(int N)
{
	// read slots
	for(int i = 0; i < N; ++i)
	{
		int row, col;
		char d;		
		scanf("%d%d %c", &row, &col, &d);
		Slot s(row-1, col-1, d);
		slots.push_back(s);
	}

	// read words
	for(int i = 0; i < N+1; ++i)
	{
		Word w;
		cin >> w.word;
		w.slotIdx = -1;

		words.push_back(w);
	}

	calculateJointPoints();
}

void CrossPuzzle::work(int slotIdx)
{
	if(slotIdx == slots.size())
	{
		addUnusedWord();
		return;
	}
	else
	{
		for(int wordIdx = 0; wordIdx < words.size(); ++wordIdx)
		{
			if(canPlace(slotIdx, wordIdx))
			{
				place(slotIdx, wordIdx);

				work(slotIdx+1);

				remove(slotIdx, wordIdx);
			}
		}
	}
}

void CrossPuzzle::calculateJointPoints()
{
	for(size_t i = 0; i < slots.size(); ++i)
	{
		for(size_t j = i+1; j < slots.size(); ++j)
		{
			if( slots[i].direction == ACROSS && slots[j].direction == DOWN &&   
				slots[i].row >= slots[j].row && slots[i].col <= slots[j].col )
			{
				CrossPoint cp1(i, j, slots[j].col-slots[i].col, slots[i].row-slots[j].row );
				slots[i].crossPoints.push_back(cp1);

				CrossPoint cp2(j, i, slots[i].row-slots[j].row, slots[j].col-slots[i].col );
				slots[j].crossPoints.push_back(cp2);
			}
			else if( slots[i].direction == DOWN && slots[j].direction == ACROSS &&
				     slots[i].row <= slots[j].row && slots[i].col >= slots[j].col )
			{
				CrossPoint cp1(i, j, slots[j].row - slots[i].row, slots[i].col - slots[j].col);
				slots[i].crossPoints.push_back(cp1);

				CrossPoint cp2(j, i, slots[i].col - slots[j].col, slots[j].row - slots[i].row);
				slots[j].crossPoints.push_back(cp2);			
			}
		}
	}
}

//  read slots and words to determin 
//  wether words[wordIdx] can be placed in slots[slotIdx].
bool CrossPuzzle::canPlace(int slotIdx, int wordIdx)
{
	// printf("can place word[%d](%s) at slot[%d]?\n", wordIdx, words[wordIdx].word.c_str(), wordIdx);
	bool result = true;

	if( words[wordIdx].slotIdx >= 0 )
		return false;

	string word = words[wordIdx].word;
	size_t wordLen = words[wordIdx].word.length();
	
	vector<CrossPoint> &cps = slots[slotIdx].crossPoints;
	for( size_t i = 0; i < cps.size(); ++i )
	{
		if( cps[i].idx1 >= wordLen ) continue;

		char crossedChar = word[cps[i].idx1];

		int crossedSlot = cps[i].slot2;
		for(size_t j = 0; j < words.size(); ++j)
		{
			if( words[j].slotIdx == crossedSlot && words[j].word[cps[i].idx2] != crossedChar)
				return false;
		}
	}

	return result;
}

int main()
{
	int i = 0;
	int N;
	while( scanf("%d", &N) != EOF && N != 0 )
	{
		CrossPuzzle puzzle;
		set<string> result;

		puzzle.init(N);

		// puzzle.print();

		puzzle.work();	
		puzzle.getResult(result);

		printf("Trial %d:", ++i);
		if(result.empty())
		{
			printf(" Impossible\n", ++i);
		}
		else
		{
			for( set<string>::iterator iter = result.begin(); iter != result.end(); ++iter )
				printf(" %s", iter->c_str());
			printf("\n");
		}
	}
	return 0;
}