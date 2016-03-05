#include <iostream>
#include "bst.h"

using namespace std;

void lca(const BST<int> &bst, const int &x, const int &y, int &a)
{
	BSTode<int> *root = bst.root;

	while(root != NULL)
	{
		a = root->data;

		if(root->data == x || root->data == y)
			break;

		else
		{
			if(root->data < x && root->data < y)
				root = root->right;

			else if(root->data > x && root->data > y)
				root = root->left;

			else
				break;
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		BST<int> bst;
		for(int i=0; i<n; i++)
		{
			int x;
			cin >> x;

			bst.insert(x);
		}

		int x,y;
		cin >> x >> y;

		int a;
		lca(bst, x, y, a);

		cout << "LCA for " << x << " & " << y << " IS " << a << endl << endl;
	}
}