/**
 * Definition for singly-linked list.
*/
 #include <stdio.h>


struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head) {
        
        return sortedListToBSTImpl(head, NULL);
    }

    TreeNode *sortedListToBSTImpl(ListNode *head, ListNode *tail) {

    	if(head == tail) return NULL;

    	ListNode *middle = get_list_middle_node(head, tail);

    	TreeNode *root = new TreeNode(middle->val);

    	root->left = sortedListToBSTImpl(head, middle);
    	root->right = sortedListToBSTImpl(middle->next, tail);

    	return root;
    }

    ListNode *get_list_middle_node(ListNode *head, ListNode *tail)
    {
    	int len = 0;
    	ListNode *p = head;
    	while(p != NULL && p != tail)
    	{
    		++len;
    		p = p->next;
    	}

    	int mid = len/2;
    	ListNode *middle = head;
    	while(mid > 0)
    	{
    		middle = middle->next;
    		--mid;
    	}

    	return middle;
    }

    void preorder_print_tree(TreeNode *tree)
    {
    	if(tree == NULL)
    	{
    		printf("# ");
    		return;
    	} 

    	printf("%d ", tree->val);
    	preorder_print_tree(tree->left);
    	preorder_print_tree(tree->right);
    }

    void print_list(ListNode *list)
    {
    	ListNode *p = list;
    	while(p != NULL)
    	{
    		printf("%d ", p->val);
    		p = p->next;
    	}
    	printf("\n");
    }
};

int main()
{
	ListNode list[5];
	for(int i = 0; i < 5; ++i)
		list[i].val = i;

	for(int i = 1; i < 5; ++i)
		list[i-1].next = &list[i];

	Solution sln;
	sln.print_list(list);

	TreeNode * tree = sln.sortedListToBST(list);

	sln.preorder_print_tree(tree);
}