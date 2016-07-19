#include <iostream>
#include "tree.h"

using namespace std;

Treeode *find_lca(Treeode *root, int node1, int node2)
{
	if(root == NULL)
		return NULL;

	else
	{
		if(root->data == node1 || root->data == node2)
			return root;

		Treeode *lca_left = find_lca(root->left, node1, node2);
		Treeode *lca_right = find_lca(root->right, node1, node2);

		if(lca_left != NULL && lca_right != NULL)
			return root;

		if(lca_left != NULL)
			return lca_left;
		else
			return lca_right;
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Tree *tree = input();

		int node1, node2;
		cin >> node1 >> node2;

		Treeode *lca = find_lca(tree->root, node1, node2);

		cout << "TREE:" << endl;
		tree->print_postorder(tree->root);
		cout << endl;

		cout << "LCA for " << node1 << " and " << node2 << " : " << lca->data << endl << endl;
	}
}