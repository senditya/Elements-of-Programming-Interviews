#include <iostream>
#include "bst.h"

using namespace std;

// BSTode<int> *find(BSTode<int> *root, int key)
// {
// 	if(root == NULL)
// 		return NULL;

// 	else
// 	{
// 		if(root->data == key)
// 			return root;

// 		else if(root->data > key)
// 			return find(root->left, key);

// 		else
// 			return find(root->right, key);
// 	}
// }

BSTode<int> *find(BSTode<int> *root, int key)
{
	BSTode<int> *current_root = root;

	while(current_root != NULL)
	{
		if(current_root->data == key)
			return current_root;

		else if(current_root->data < key)
			current_root = current_root->right;

		else
			current_root = current_root->left;
	}

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

		vector<int> numbers(n);
		for(int i=0; i<n; i++)
			cin >> numbers[i];

		BST<int> bst;
		bst.construct(numbers);

		int key;
		cin >> key;

		BSTode<int> *node = find(bst.root, key);

		if(node == NULL)
			cout << "ABSENT" << endl << endl;
		else
			cout << "Found node " << node->data << endl << endl;
	}
}