#include <iostream>
#include "tree.h"

using namespace std;

bool check_leaves(Treeode *root, int sum, int n)
{
	sum += root->data;

	if(root->left == NULL && root->right == NULL)
	{
		if(sum == n)
			return true;
		else
			return false;
	}

	else
	{
		bool in_left = false, in_right = false;

		if(root->left != NULL)
			in_left = check_leaves(root->left, sum, n);
		
		if(root->right != NULL)
			in_right = check_leaves(root->right, sum, n);

		if(in_left || in_right)
			return true;
		else
			return false;
	}
}

bool leaf_exists(Tree *tree, int n)
{
	if(tree->root == NULL)
		return false;

	else
	{
		int sum = 0;
		return check_leaves(tree->root, sum, n);
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Tree *tree = input();

		int n;
		cin >> n;

		bool exists = leaf_exists(tree, n);

		cout << "TREE:" << endl;
		tree->print_inorder(tree->root);
		cout << endl;

		if(exists)
			cout << "EXISTS" << endl << endl;
		else
			cout << "DOES NOT EXIST" << endl << endl;
	}
}