#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 27
typedef char string[MAXLEN];

struct BinaryTree
{
	char val;
	BinaryTree *left;
	BinaryTree *right;
	BinaryTree():val(0), left(NULL), right(NULL){}
};

bool read_tree(char *preorder, char *inorder);
BinaryTree* construct_tree(char *preorder, char *inorder);
void print_post_order(BinaryTree *root);
void destroy_tree(BinaryTree *root);

int main()
{
	string preorder, inorder;
	while( read_tree(preorder, inorder) )
	{
		BinaryTree *root = construct_tree(preorder, inorder);

		print_post_order(root);
		printf("\n");

		destroy_tree(root);
	}

	return 0;
}

bool read_tree(char *preorder, char *inorder)
{
	char c = getchar();
	if(c == EOF) return false;

	int i = 0;
	preorder[i++] = c;
	while( (c=getchar()) != EOF && c >= 'A' && c <= 'Z' )
		preorder[i++] = c;
	preorder[i] = '\0';

	while( (c=getchar()) != EOF && (c<'A' || c>'Z') );

	i = 0;
	inorder[i++] = c;

	int len = strlen(preorder);
	while(i<len)
		inorder[i++] = getchar();
	inorder[i] = '\0';

	while( (c=getchar())!=EOF && c!= '\n' );

	return true;
}

BinaryTree* construct_tree(char *preorder, char *inorder)
{
	int prelen = strlen(preorder);

	if(prelen == 0) return NULL;

	BinaryTree* root = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->val = preorder[0];

	int pos = 0;
	while( inorder[pos] != preorder[0] )
		++pos;

	string left_child_preorder, right_child_preorder;
	string left_child_inorder, right_child_inorder; 

	int i = 0;
	for(; i < pos; ++i)
	{
		left_child_preorder[i] = preorder[i+1];
		left_child_inorder[i] = inorder[i];
	}
	left_child_preorder[i] = left_child_inorder[i] = '\0';

	for(i = 0; i < prelen-pos-1; ++i)
	{
		right_child_preorder[i] = preorder[i+pos+1];
		right_child_inorder[i] = inorder[i+pos+1];
	}
	right_child_preorder[i] = right_child_inorder[i] = '\0';

	root->left = construct_tree(left_child_preorder, left_child_inorder);
	root->right = construct_tree(right_child_preorder, right_child_inorder);

	return root;
}


void print_post_order(BinaryTree *root)
{
	if(root == NULL) return;

	print_post_order(root->left);
	print_post_order(root->right);
	printf("%c", root->val);
}

void destroy_tree(BinaryTree *root)
{
	if(root == NULL) return;

	destroy_tree(root->left);
	destroy_tree(root->right);
	delete root;
}