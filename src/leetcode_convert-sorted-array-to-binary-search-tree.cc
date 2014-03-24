#include <stdio.h>
#include <vector>
using namespace std;
/**
 * Definition for binary tree
 *  */
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {

    	TreeNode *root = sortedArrayToBSTImpl(num, 0, num.size());
    	return root;
    }

    TreeNode *sortedArrayToBSTImpl(vector<int> &num, size_t beg, size_t end) {

    	if(beg >= end) return NULL;

    	size_t mid = (end+beg)/2;
    	TreeNode *root = new TreeNode(num[mid]);

    	root->left = sortedArrayToBSTImpl(num, beg, mid);
    	root->right = sortedArrayToBSTImpl(num, mid+1, end);

    	return root;
    }

    void preorder_print(TreeNode *root)
    {
    	if(root == NULL) return;

    	printf("%d ", root->val);
    	preorder_print(root->left);
    	preorder_print(root->right);
    }
};

