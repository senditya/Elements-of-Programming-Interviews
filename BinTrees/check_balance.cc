#include "tree.h"
#include <iostream>
#include <utility>

using namespace std;

pair<bool,int> check_balance(Treeode *root)
{
	if(root)
	{
		pair<bool, int> balance_left = check_balance(root->left);
		//cout << root->data << " left=" << balance_left.second << endl;

		if(balance_left.first)
		{
			pair<bool, int> balance_right = check_balance(root->right);
			//cout << root->data << " right=" << balance_right.second << endl;
			if(balance_right.first)
			{
				int diff = balance_left.second - balance_right.second;

				if(diff == 1 || diff == -1 || diff == 0)
				{
					if(diff == 1)
						return make_pair(true, balance_left.second+1);
					else
						return make_pair(true, balance_right.second+1);
				}

				else
					return make_pair(false, -1);
			}

			else
				return make_pair(false, -1);
		}

		else
			return make_pair(false, -1);
	}

	else
		return make_pair(true, -1);
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
		for(int i=0; i<n; i++)
		{
			string s;
			cin >> s;
			elements.push_back(s);
		}

		Tree *tree = new Tree();
		tree->construct_tree(tree->root, elements);

		pair<bool,int> balanced = check_balance(tree->root);

		cout << "TREE, INORDER:" << endl;
		tree->print_preorder(tree->root);
		cout << endl;

		if(balanced.first)
			cout << "TREE IS BALANCED" << endl << endl;
		else
			cout << "NOT BALANCED" << endl << endl;
	}
}