#include <iostream>
#include "tree.h"

using namespace std;

int str2int(string path)
{
	int num = 0;

	for(int i=0; i<path.length(); i++)
		num = 2*num + path[i] - '0';

	return num;
}

void dfs(Treeode *root, int &sum, string path)
{
	path = path + string(1, char(root->data)+'0');
	//cout << path << endl;

	if(root->left == NULL && root->right == NULL)
	{
		//cout << "adding to sum: " << path << " = " << str2int(path) << endl;
		sum += str2int(path);
	}

	if(root->left != NULL)
		dfs(root->left, sum, path);
	
	if(root->right != NULL)
		dfs(root->right, sum, path);
}

int sum_paths(Treeode *root)
{
	if(root == NULL)
		return 0;

	else
	{
		int sum = 0;
		string path = "";

		dfs(root, sum, path);

		return sum;
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Tree *tree = input();

		cout << "TREE:" << endl;
		tree->print_preorder(tree->root);
		cout << endl;

		int sum = sum_paths(tree->root);
		cout << "Sum of paths = " << sum << endl << endl;
	}
}