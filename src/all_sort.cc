#include <stdio.h>
#include <malloc.h>
/*
insertion sort
*/
void InsertionSort(int *A, int N)
{
	for(int i = 1; i < N; ++i)
	{
		int tmp = A[i];
		int j = i;
		for(; j > 0 && A[j-1] > tmp; --j)
			A[j] = A[j-1];

		A[j] = tmp;
	}
}

/*
Shell Sort
*/
void ShellSort(int *A, int N)
{
	for(int h = N/2; h >= 1; h /= 2)
	{
		for(int i = h; i < N; ++i)
		{
			int tmp = A[i];
			int j = i;
			for(; j >= h; j -= h)
			{
				if(A[j-h] > tmp)
					A[j] = A[j-h];
				else
					break;
			}

			A[j] = tmp;
		}
	}
}

/*
heap sort
*/
#define LeftChild(i) (2*(i) + 1)

void precDown(int *A, int i, int N)
{
	int child;
	int tmp = A[i];
	for(; LeftChild(i) < N; i = child)
	{
		child = LeftChild(i);
		if( child < N-1 && A[child] < A[child+1] )
			child++;

		if(tmp < A[child])
			A[i] = A[child];
		else
			break;
	}

	A[i] = tmp;
}

void HeapSort(int *A, int N)
{
	for(int i = N/2; i >=0; --i)
		precDown(A, i, N);

	for(int i = N-1; i >0; --i)
	{
		int tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;

		precDown(A, 0, i);
	}
}

/*
merge sort
*/
void MSort(int *A, int *tmp, int left, int right);
void Merge(int *A, int *tmp, int lpos, int rpos, int rend);
void mergeSort(int *A, int N)
{
	int *tmp = (int *)malloc(N*sizeof(int));

	MSort(A, tmp, 0, N-1);
}

void MSort(int *A, int *tmp, int left, int right)
{
	if(left >= right) return;

	int center = (left+right)/2;

	MSort(A, tmp, left, center);
	MSort(A, tmp, center+1, right);
	Merge(A, tmp, left, center+1, right);
}
void Merge(int *A, int *tmp, int lpos, int rpos, int rend)
{
	int i = lpos, j = rpos, k = lpos;

	while(i < rpos && j <= rend)
	{
		if(A[i] < A[j])
			tmp[k++] = A[i++];
		else
			tmp[k++] = A[j++];
	}

	while(i < rpos)
		tmp[k++] = A[i++];
	while(j <= rend)
		tmp[k++] = A[j++];

	for(i = lpos; i <= rend; ++i)
		A[i] = tmp[i];
}

/*
*quick sort
*/
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int pivort(int *A, int left, int right)
{
	int center = (left+right)/2;

	if(A[left] > A[center]) swap(A[left], A[center]);
	if(A[center] > A[right]) swap(A[center], A[right]);
	if(A[left] > A[center] ) swap(A[left], A[center]);

	swap(A[center], A[right-1]);
	
	return A[right-1];
}
void QSort(int *A, int left, int right);
void quickSort(int *A, int N)
{
	QSort(A, 0, N-1);
}

void QSort(int *A, int left, int right)
{
	if(left + 10 <= right)
	{
		int tmp = pivort(A, left, right);
		int i = left, j = right-1;
		
		while(1)
		{
			while( A[++i] < tmp );
			while( A[--j] > tmp );

			if(i < j)
				swap(A[i], A[j]);
			else
				break;
		}
		
		swap(A[i], A[right-1]);

		QSort(A, left, i-1);
		QSort(A, i+1, right);
	}
	else
		InsertionSort(A+left, right-left+1); //
}
