// 请给出一个运行时间为O(nlogn)的算法，是之能在给定一个由n个整数构成的集合S
// 和另一个整数x时，判断出S中是否存在有两个其和等于x的元素
// input: the first line is n(0<=n<=1000), then n line with S[i](0<=S[i]<=1000). 
// then x, end with 0
// output: if possible, output s[i] s[j] in one line; else, print impossible
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main()
{
	int n;
	while( scanf("%d\n", &n) != EOF && n != 0 )
	{
		int *a = (int*)malloc(n*sizeof(int));
		read_set(a, n);
		std::sort(a, a+0, a+n);

		int x;
		scanf("%d\n", &x);

		int mid = getPos(a, len, x/2);
		int i = mid, j = mid+1;
		while(i>=0 && j<n)
		{
			if(a[i]+a[j] < x)
				++j;
			else if(a[i] + a[j] > x)
				--i;
			else
			{
				printf("%d %d\n", a[i], a[j]);
				break;
			}
		}

		if(i<0 || j>=n)
			printf("Impossible");
	}
	return 0;
}

