#include <stdio.h>
#include <math.h>

/**
 * Definition for binary tree
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        
        int depth = 0;
        return isBalancedImpl( root, depth );
    }

    bool isBalancedImpl(TreeNode *root, int &depth)
    {
    	if(root == NULL)
    	{
    		depth = 0;
    		return true;
    	}

    	int leftDepth = 0, rightDepth = 0;
    	if( isBalancedImpl(root->left, leftDepth) == false ||
    	    isBalancedImpl(root->right, rightDepth) == false )
    	    return false;

    	depth = (leftDepth>rightDepth? leftDepth: rightDepth) + 1;

    	int diff = fabs((double)leftDepth-(double)rightDepth);
    	return diff <= 1; 
    }
};