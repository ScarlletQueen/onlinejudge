/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxPathSum(TreeNode *root) {
    	if(root==NULL) return 0;

    	int leftMax = maxPathSum(root->left);
    	int rightMax = maxPathSum(root->right);

    	int middleMax = maxMiddlePath(root);

    	int temp = leftMax > rightMax? leftMax: rightMax;
    	return temp > middleMax? temp: middleMax;
    }

    int maxMiddlePath(TreeNode *root)
    {
    	if(root == NULL) return 0;
    
    	int result = root->val;

    	int leftMax = maxMiddlePath(root->left);

    	int rightMax = maxMiddlePath(root->right);

    	if(leftMax > 0) result += leftMax;
    	if(rightMax > 0) result += rightMax;

    	return result;
    }
};