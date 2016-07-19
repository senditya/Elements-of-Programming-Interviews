#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

vector<int> range_search(BSTode<int> *root, int &lower, int &upper)
{
	if(root == NULL)
		return vector<int>();

	else
	{
		if(root->data < lower)
			return range_search(root->right, lower, upper);

		else if(root->data > upper)
			return range_search(root->left, lower, upper);

		else
		{
			vector<int> left_range = range_search(root->left, lower, root->data);
			vector<int> right_range = range_search(root->right, root->data, upper);

			vector<int> range = left_range;
			range.push_back(root->data);
			range.insert(range.end(), right_range.begin(), right_range.end());

			return range;
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
		
		int lower, upper;
		cin >> lower >> upper;

		vector<int> range = range_search(bst.root, lower, upper);

		bst.print("preorder");
		cout << "[" << lower << "," << upper << "]" << endl;
		cout << "{";
		for(int i=0; i<(int)range.size()-1; i++)
			cout << range[i] << ",";
		cout << range[(int)range.size()-1] << "}" << endl << endl;
	}
}