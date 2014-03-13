/**
 * Definition for binary tree
 */
 #include <vector>
 using namespace::std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        
        if(root == NULL) return result;
        
        result.push_back(root->val);

        vector<int> leftresult = preorderTraversal(root->left);
        vector<int> rightresult = preorderTraversal(root->right);
        
        result.insert(result.end(), leftresult.begin(), leftresult.end());
        result.insert(result.end(), rightresult.begin(), rightresult.end());

        return result;
    }
};