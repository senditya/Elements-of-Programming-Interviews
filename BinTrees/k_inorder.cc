#include <iostream>
#include "tree.h"

using namespace std;

Treeode *inorder(Treeode *root, int k)
{
	if(root == NULL || k == 0)
		return NULL;

	else
	{
		if(root->left != NULL)
		{
			if(k <= root->left->data)
				return inorder(root->left, k);

			else if(k == root->left->data + 1)
				return root;

			else
				return inorder(root->right, k-(root->left->data+1));
		}

		else
		{
			if(k==1)
				return root;

			else
				return inorder(root->right, k-1);
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Tree *tree = input();

		int k;
		cin >> k;

		Treeode *k_node = inorder(tree->root, k);

		cout << "TREE:" << endl;
		tree->print_inorder(tree->root);
		cout << endl;

		if(k_node != NULL)
			cout << k << "-th node in inorder traversal is: " << k_node->data << endl << endl;
		else
			cout << k << "-th node does not exist in inorder traversal" << endl << endl;
	}
}