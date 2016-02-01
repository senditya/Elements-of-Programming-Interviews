#include <iostream>
#include "tree.h"

using namespace std;

void inorder(Treeode *root, vector<char> &order)
{
	if(root != NULL)
	{
		inorder(root->left, order);
		order.push_back(root->data+'A');
		inorder(root->right, order);
	}
}

void preorder(Treeode *root, vector<char> &order)
{
	if(root != NULL)
	{
		order.push_back(root->data+'A');
		preorder(root->left, order);
		preorder(root->right, order);
	}
}

void postorder(Treeode *root, vector<char> &order)
{
	if(root != NULL)
	{
		postorder(root->left, order);
		postorder(root->right, order);
		order.push_back(root->data+'A');
	}
}

Treeode *generate(vector<char> pre, int &start)
{
	if(pre[start] == 'n')
	{
		start++;
		return NULL;
	}

	else
	{
		Treeode *root = new Treeode();
		root->data = int(pre[start]-'A');

		start++;

		root->left = generate(pre, start);
		root->right = generate(pre, start);

		return root;
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

		vector<char> pre;

		for(int i=0; i<n; i++)
		{
			char a;
			cin >> a;
			pre.push_back(a);
		}

		Tree *tree = new Tree();

		int start=0;
		tree->root = generate(pre, start);
		
		vector<char> in, post;
		inorder(tree->root, in);
		postorder(tree->root, post);

		for(int i=0; i<(int)in.size(); i++)
			cout << in[i] << " ";
		cout << endl;

		for(int i=0; i<(int)post.size(); i++)
			cout << post[i] << " ";
		cout << endl;

		cout << endl;
	}
}