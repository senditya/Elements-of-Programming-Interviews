#include <iostream>
#include "../BinTrees/tree.h"
#include <vector>
#include <utility>

using namespace std;

bool check_BST(Treeode *root, pair<int,int> &extremes)
{
	if(root->left == NULL)
		extremes.first = root->data;
	else
	{
		pair<int,int> left_extremes;

		if(!check_BST(root->left, left_extremes))
			return false;

		if(left_extremes.second > root->data)
			return false;

		extremes.first = left_extremes.first;
	}

	if(root->right == NULL)
		extremes.second = root->data;
	else
	{
		pair<int,int> right_extremes;

		if(!check_BST(root->right, right_extremes))
			return false;

		if(right_extremes.first <= root->data)
			return false;

		extremes.second = right_extremes.second;
	}

	return true;
}

bool is_BST(Treeode *root)
{
	if(root == NULL)
		return true;

	else
	{
		pair<int,int> extremes;
		return check_BST(root, extremes);
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Tree *tree = input();

		if(is_BST(tree->root))
			cout << "BST" << endl << endl;
		else
			cout << "NOT BST" << endl << endl;
	}
}