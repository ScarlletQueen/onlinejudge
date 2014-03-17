#include <stdio.h>
#include <string.h>

#define MAXLEN 1001
#define MAXCHANGES 101

typedef char string[MAXLEN];

string mergers[MAXLEN][2];
int nmergers;

void readChanges();
void read_quoted_string(char *s);
void printChanges();
int findmatch(char *p, char *t);
void replace_x_with_y(char *s, int pos, int xlen, char *y);

void readChanges()
{
	scanf("%d\n", &nmergers);
	for(int i = 0; i < nmergers; ++i)
	{
		read_quoted_string(mergers[i][0]);
		read_quoted_string(mergers[i][1]);
	}
}

void read_quoted_string(char *s)
{
	int i = 0;
	char c;
	
	while((c = getchar()) != '\"');
	while((c = getchar()) != '\"')
		s[i++] = c;

	s[i] = '\0';
}

void printChanges()
{
	for(int i = 0; i < nmergers; ++i)
	{
		printf("%s\t", mergers[i][0]);
		printf("%s", mergers[i][1]);
	}
}

int findmatch(char *p, char *t)
{
	int plen = strlen(p);
	int tlen = strlen(t);

	for(int i = 0; i < (tlen-plen); ++i )
	{
		int j = 0;
		while( (j<plen) && (p[j]==t[i+j]) )
			++j;

		if(j == plen) return i;
	}

	return -1;
}

void replace_x_with_y(char *s, int pos, int xlen, char *y)
{
	int slen = strlen(s);
	int ylen = strlen(y);

	if(xlen > ylen)
		for(int i = pos+xlen; i <= slen; ++i)
			s[i-xlen+ylen] = s[i];
	else if(xlen < ylen)
		for(int i = slen; i >= (pos+xlen); --i)
			s[i+ylen-xlen] = s[i];

	for(int i = 0; i < ylen; ++y)
		s[pos+i] = y[i];
}

int main()
{
	readChanges();

	int nlines;
	scanf("%d\n", &nlines);

	for(int i = 0; i < nlines; ++i)
	{
		string s;
		char c;
		int j = 0;
		while( (c=getchar()) != '\n' )
			s[j++] = c;

		s[j] = '\0';

		for(int j = 0; j < nmergers; ++j)
		{
			int pos = 0;
			while( (pos = findmatch(mergers[j][0], s)) != -1 )
				replace_x_with_y(s, pos, strlen(mergers[j][0]), mergers[j][1]);
		}

		printf("%s\n", s);
	}

	return 0;
}