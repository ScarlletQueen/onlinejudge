#include <stdio.h>

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
    void flatten(TreeNode *root) {

        if(root == NULL) return;

        TreeNode *orgLeft = root->left;
        TreeNode *orgRight = root->right;

        flatten(root->left);
        flatten(root->right);

        TreeNode *lastInLeft = get_rightest_node(orgLeft);
        if(lastInLeft != NULL)
        {
	        lastInLeft->right = orgRight;
	        root->right = orgLeft;        	
        }
        else
        {
        	root->right = orgRight;
        }

        root->left = NULL;
    }

    TreeNode * get_rightest_node(TreeNode *root)
    {
    	if(root == NULL) return NULL;

    	TreeNode * result = root;

    	while(result->right != NULL)
    	{
    		result = result->right;
    	}

    	return result;
    }

    void preorder_print(TreeNode *root)
    {
    	if(root==NULL)
    	{
    		printf("#, ");
    		return;
    	} 

    	printf("%d, ", root->val);
    	preorder_print(root->left);
    	preorder_print(root->right);
    }
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	left->left = new TreeNode(3);
	// TreeNode *right = new TreeNode(3);
	root->left = left;

	Solution sln;

	sln.flatten(root);

	printf("after flattern\n");
	sln.preorder_print(root);
	printf("\n");
}