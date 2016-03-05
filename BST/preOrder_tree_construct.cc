#include <iostream>
#include <climits>
#include "bst.h"

using namespace std;

BSTode<int> *pre_construct(int *preOrder, int &len, int &start, int limit=INT_MAX)
{
	if(start < len)
	{
		if(preOrder[start] <= limit)
		{
			BSTode<int> *root = new BSTode<int>();

			root->data = preOrder[start];
			start++;

			root->left = pre_construct(preOrder, len, start, root->data);
			root->right = pre_construct(preOrder, len, start, limit);

			return root;
		}

		else
			return NULL;
	}

	else
		return NULL;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int preOrder[n];
		for(int i=0; i<n; i++)
			cin >> preOrder[i];

		BST<int> bst;
		int start = 0;
		
		bst.root = pre_construct(preOrder, n, start);

		bst.print_preorder(bst.root);
		cout << endl;
		bst.print_inorder(bst.root);
		cout << endl << endl;
	}
}