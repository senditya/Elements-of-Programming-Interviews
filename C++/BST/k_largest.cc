#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

void find_k_largest(BSTode<int> *root, int &k, vector<int> &largest)
{
	if(root != NULL)
	{
		if(k>0)
		{
			find_k_largest(root->right, k, largest);

			if(k > 0)
			{
				largest.insert(largest.begin(), root->data);
				k--;
			}

			if(k > 0)
				find_k_largest(root->left, k, largest);
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

		int k;
		cin >> k;

		bst.print_bft();
		cout << " : " << k << endl;

		vector<int> largest;
		find_k_largest(bst.root, k, largest);

		for(int i=0; i<(int)largest.size(); i++)
			cout << largest[i] << " ";
		cout << endl << endl;
	}
}