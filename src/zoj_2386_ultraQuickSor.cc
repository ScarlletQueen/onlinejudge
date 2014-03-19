#include <stdio.h>
#include <stdlib.h>

void read_array(unsigned long *arr, int len);
int ultra_quick_sort_small(unsigned long *arr, int len);
unsigned long long ultra_quick_sort(unsigned long *arr, int beg, int end);
void print_array(unsigned long *arr, int len);
void print_array(unsigned long *arr, int beg, int end);

int main()
{
	int len = 0;
	while( scanf("%d\n", &len) != EOF && len > 0 )
	{
		unsigned long *arr = (unsigned long *)malloc(sizeof(unsigned long)*len);
		read_array(arr, len);

		unsigned long long step = ultra_quick_sort(arr, 0, len);

		printf("%llu\n", step);
		free(arr);
	}

	return 0;
}

void read_array(unsigned long *arr, int len)
{
	for(int i = 0; i < len; ++i)
		scanf("%lu", arr + i);
}

int ultra_quick_sort_small(unsigned long *arr, int len)
{
	// print_array(arr, len);

	int step = 0;

	for(int i = 0; i < len-1; ++i)
	{
		for(int j = i+1; j < len; ++j)
		{
			if (arr[i] > arr[j])
				++step;
		}
	}

	return step;
}

void print_array(unsigned long *arr, int len)
{
	print_array(arr, 0, len);
}

void print_array(unsigned long *arr, int beg, int end)
{
	for(int i = beg; i < end; ++i)
		printf("%lu ", arr[i]);
	printf("\n");
}

unsigned long long ultra_quick_sort(unsigned long *arr, int beg, int end)
{	
	if(beg+1 >= end) return 0;

	int mid = (beg+end)/2;
	unsigned long long leftStep = ultra_quick_sort(arr, beg, mid);
	unsigned long long rightStep = ultra_quick_sort(arr, mid, end);
	// printf("leftstep = %d, rightStep = %d, begin merge arr[%d, %d, %d]\n",
	// 	leftStep, rightStep, beg, mid, end);
	// print_array(arr, beg, end);

	//merge
	unsigned long long step = 0;
	unsigned long *tmp = (unsigned long*)malloc((end-beg)*sizeof(unsigned long) );
	
	int i = beg, j = mid, k=0;
	while(i<mid && j<end)
	{
		if(arr[i] < arr[j])
		{
			tmp[k++]=arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
			step += (mid-i);
		}
	}

	while(i < mid)
	{
		tmp[k++] = arr[i++];
	}

	while(j < end)
	{
		tmp[k++] = arr[j++];
	}

	for(i=beg, k=0; i<end; ++i,++k)
		arr[i] = tmp[k];

	// print_array(arr, beg, end);
	free(tmp);
	return step+leftStep+rightStep;
}