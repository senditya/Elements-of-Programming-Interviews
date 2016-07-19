#include <iostream>
#include <vector>
#include <utility>
#include "bst.h"

using namespace std;

bool total_ordering(BST<int> &bst, int &mid, vector<int> &extremes)
{
	int first = -1;
	BSTode<int> *subroot = bst.root;

	while(subroot != NULL && subroot->data != mid)
	{
		if(subroot->data == extremes[0])
			first = 0;
		else if(subroot->data == extremes[1])
			first = 1;
		
		if(subroot->data > mid)
			subroot = subroot->left;
		else
			subroot = subroot->right;
	}

	if(subroot == NULL)
		return false;

	else
	{
		if(first == -1)
			return false;

		int second = 1-first;

		while(subroot != NULL)
		{
			if(subroot->data == extremes[second])
			{
				if(subroot->data == mid)
					return false;
				else
					return true;
			}
			else if(subroot->data > extremes[second])
				subroot = subroot->left;
			else
				subroot = subroot->right;
		}

		return false;
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

		vector<int> extremes(2);
		cin >> extremes[0] >> extremes[1];

		int mid;
		cin >> mid;

		bst.print("preorder");
		cout << "{" << extremes[0] << "," << mid << "," << extremes[1] << "} ";
		if(!total_ordering(bst, mid, extremes))
			cout << "do not ";
		cout << "have total ordering" << endl << endl;
	}
}