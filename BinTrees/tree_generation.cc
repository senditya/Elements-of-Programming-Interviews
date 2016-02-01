#include <iostream>
#include "tree.h"

using namespace std;

void inorder(Treeode *root, vector<int> &order)
{
	if(root != NULL)
	{
		inorder(root->left, order);
		order.push_back(root->data);
		inorder(root->right, order);
	}
}

void preorder(Treeode *root, vector<int> &order)
{
	if(root != NULL)
	{
		order.push_back(root->data);
		preorder(root->left, order);
		preorder(root->right, order);
	}
}

void postorder(Treeode *root, vector<int> &order)
{
	if(root != NULL)
	{
		postorder(root->left, order);
		postorder(root->right, order);
		order.push_back(root->data);
	}
}

Treeode *generate(Treeode *root, vector<int> &in, vector<int> &pre, int length, int in_start=0, int pre_start=0)
{
	if(length == 0)
		return NULL;

	else
	{
		int root_data = pre[pre_start];

		int in_end = in_start;
		while(in[in_end] != root_data)
			in_end++;

		root = new Treeode();
		root->data = root_data;

		root->left = generate(root, in, pre, in_end-in_start, in_start, pre_start+1);
		root->right = generate(root, in, pre, length-(in_end-in_start)-1, in_end+1, pre_start+1+in_end-in_start);

		return root;
	}
}

bool same(vector<int> a, vector<int> b)
{
	int n = (int)a.size();

	if(b.size() != n)
		return false;

	else
	{
		for(int i=0; i<n; i++)
		{
			if(a[i] != b[i])
				return false;
		}

		return true;
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

		vector<int> in, pre;
		int x;
		for(int i=0; i<n; i++)
		{
			cin >> x;
			in.push_back(x);
		}
		for(int i=0; i<n; i++)
		{
			cin >> x;
			pre.push_back(x);
		}

		Tree *tree = new Tree();

		tree->root = generate(tree->root, in, pre, n);

		vector<int> gen_in, gen_pre;
		inorder(tree->root, gen_in);
		preorder(tree->root, gen_pre);

		if(same(in, gen_in) && same(pre, gen_pre))
			cout << "CORRECT TREE GENERATION" << endl;
		else
			cout << "INCORRECT TREE GENERATION" << endl;
	}
}