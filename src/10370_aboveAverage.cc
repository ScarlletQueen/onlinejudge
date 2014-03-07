#include <stdio.h>

int main()
{
	unsigned C = 0;
	scanf("%u", &C);
	if(C==0) return 0;

	for(unsigned line = 0; line < C; ++line)
	{
		// get student count;
		unsigned N = 0;
		scanf("%u", &N);
		
		unsigned *score = new unsigned[N];
		unsigned sum = 0, avg = 0;

		// get student score
		for(unsigned i = 0; i < N; ++i)
		{
			scanf("%u", &score[i]);
			sum += score[i];			
		}
		avg = sum / N;

		unsigned aboveAvgCount = 0;
		for(unsigned i = 0; i < N; ++i)
		{
			if(score[i] > avg)
				++aboveAvgCount;
		}

		double rate = ((double)aboveAvgCount / (double)N) * 100;
		printf("%.3f%%\n", rate);
	}
}