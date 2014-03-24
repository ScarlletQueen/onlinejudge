class Solution {
public:
    int maxSubArray(int A[], int n) {

        int max = A[0];
        for(int i = 0; i < n; ++i)
        {
        	if(A[i] > max)
        		max = A[i];
        }

        if(max < 0) return max;

        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
        	sum += A[i];

        	if(sum < 0)
        		sum = 0;

        	if(sum > max)
        		max = sum;
        }

        return max;
    }
};