#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct Pair
{
	int x;
	string s;
};

void Merge(Pair **arr, Pair **tmp, int lbeg, int rbeg, int rend)
{
	cout << "MERGE " << lbeg <<" : " << rbeg << " : " << rend << endl;
	int i = lbeg, j = rbeg, k = lbeg;

	while( i < rbeg && j <= rend )
	{
		if( arr[i]->x < arr[j]->x )
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	while(i < rbeg)
		tmp[k++] = arr[i++];
	while(j <= rend)
		tmp[k++] = arr[j++];

	for(int idx = lbeg; idx <= rend; ++idx)
		arr[idx] = tmp[idx];
}

void MSort(Pair **arr, Pair **tmp, int left, int right)
{
	if(left < right)
	{
		cout << "MSORT " << left << " : " << right <<endl; 
		int center = (left + right)/2;
		
		MSort(arr, tmp, left, center);
		MSort(arr, tmp, center+1, right);
		Merge(arr, tmp, left, center+1, right);
	}
}

void mergeSort(Pair **arr, int N)
{
	Pair **tmp = new Pair*[N];

	MSort(arr, tmp, 0, N-1);

}

int main()
{
	int N;
	cin >> N;
	cout << N << endl;


	Pair *arr = new Pair[N];
	Pair **helperArr = new Pair*[N];

	for(int i = 0; i < N; ++i )
	{
		cin >> arr[i].x >> arr[i].s;
		if(i < N/2)
			arr[i].s = "-";

		cout << arr[i].x << "_" << arr[i].s << endl; 

		helperArr[i] = arr + i;
	}

	mergeSort(helperArr, N);

	for(int i = 0; i < N; ++i)
	{
		cout << helperArr[i]->s << " ";
	}

	return 0;
}