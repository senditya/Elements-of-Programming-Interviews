#include <iostream>
#include "tree.h"

using namespace std;

// int exp2(int n)
// {
// 	int p = 1;

// 	for(int i=0; i<n; i++)
// 		p *= 2;

// 	return p;
// }

int main()
{
	int h;
	cin >> h;

	int n = exp2(h+1)-1;

	string s;
	vector<string> array;

	for(int i=0; i<n; i++)
	{
		cin >> s;
		array.push_back(s);
	}

	Tree *tree = new Tree();
	tree->construct_tree(tree->root, array);

	cout << (tree->root)->data << endl;

	tree->print_preorder(tree->root);
	cout << endl;
}