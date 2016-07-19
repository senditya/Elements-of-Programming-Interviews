#include <iostream>
#include "tree.h"

using namespace std;

bool reflection(Treeode *left, Treeode *right)
{
	if(left == NULL && right != NULL)
		return false;

	else if(left != NULL && right == NULL)
		return false;

	else if(left == NULL && right == NULL)
		return true;

	else
	{
		if(reflection(left->left, right->right) && reflection(left->right, right->left))
		{
			if(left->data == right->data)
				return true;
		}

		return false;
	}
}

bool symmetrical(Tree *tree)
{
	if(tree->root == NULL)
		return true;

	else
		return reflection(tree->root->left, tree->root->right);
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int h;
		cin >> h;

		int n = exp2(h+1)-1;
		vector<string> elements;
		Tree *tree = new Tree();

		for(int i=0; i<n; i++)
		{
			string s;
			cin >> s;
			elements.push_back(s);
		}

		tree->construct_tree(tree->root, elements);

		cout << "TREE:" << endl;
		tree->print_inorder(tree->root);
		cout << endl;
		
		if(symmetrical(tree))
			cout << "SYMMETRICAL" << endl << endl;
		else
			cout << "ASYMMETRICAL" << endl << endl;
	}
}