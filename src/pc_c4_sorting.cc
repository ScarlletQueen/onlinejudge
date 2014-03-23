#include <stdio.h>

int unique(int *arr, int beg, int end);
void print_array(int *arr, int beg, int end);

int main()
{
	int A[] = {1, 1, 1, 2, 2};

	print_array(A, 0, sizeof(A)/sizeof(A[0]));

	int back = unique(A, 0, sizeof(A)/sizeof(A[0]));

	print_array(A, 0, back);

}

void print_array(int *arr, int beg, int end)
{
	for(int i = beg; i < end; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int unique_v1(int *arr, int beg, int end)
{
	printf("beg = %d, end=%d\n", beg, end);
	int i = 1, j = 2;
	int idx = end;

	int N = end - beg;

	for( i=1,j=2; i < N && j < N; )
	{
		while(i < N && arr[beg+i] != arr[beg+i-1]) 
			++i;

		printf("i=%d\n", i);
		j = i+1;

		while(j < N && arr[beg+j] == arr[beg+j-1])
			++j;
		printf("j=%d\n", j);

		if( i>=N || j>= N )
			break;

		idx = i + 1;

		arr[beg+i] = arr[beg+j];
	}

	return idx;
}

int unique_v2(int *arr, int beg, int end)
{
	int idx = end, i= beg+1, j;
	while(1)
	{
		while(i < end && arr[i] != arr[j-1])
			++i;

		if(i >= end) break;

		idx = i+1;
		j = i+1;

		while(j < end && arr[j] == arr[j-1])
			++j;

		if(j >= end) break;

		arr[i] = arr[j];
	}

	return idx;
}

int unique(int *arr, int beg, int end)
{
	int back = beg, i = beg+1;

	for(int i = beg+1; i < end; ++i)
	{
		if( arr[i] != arr[back] )
		{
			++back;
			arr[back] = arr[i];
		}
	}

	return back + 1;
}