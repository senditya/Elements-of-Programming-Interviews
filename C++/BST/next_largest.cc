#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

bool larger(BST<int> &bst, int &key, int &x)
{
	BSTode<int> *subroot = bst.root;
	x = key-1;

	while(subroot)
	{
		if(subroot->data <= key)
			subroot = subroot->right;

		else
		{
			x = subroot->data;
			subroot = subroot->left;
		}
	}

	if(x > key)
		return true;
	else
		return false;
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

		int key;
		cin >> key;

		bst.print_bft();
		cout << " : " << key << endl;

		int x;
		if(larger(bst, key, x))
			cout << x << endl;
		else
			cout << "NO LARGER ELEMENT FOUND" << endl;
		cout << endl;
	}
}