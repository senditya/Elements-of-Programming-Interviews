#include <iostream>
#include <vector>

using namespace std;

int exp2(int n)
{
	int p = 1;

	for(int i=0; i<n; i++)
		p *= 2;

	return p;
}

class Treeode
{
	public:
		int data;
		Treeode *left;
		Treeode *right;
		Treeode *level_next;
		Treeode *next;
		Treeode *prev;

		Treeode()
		{
			left = NULL;
			right = NULL;
			level_next = NULL;
			next = NULL;
			prev = NULL;
		}
};

int str2num(string &s)
{
	int n = s.length();
	int num = 0;

	for(int i=0; i<n; i++)
		num = 10*num + s[i] - '0';

	return num;
}

class Tree
{
	public:
		Treeode *root;

		void construct_tree(Treeode *&root, vector<string> &nodes, int index=0)
		{
			//cout << index << ":" << nodes[index] << endl;

			if(nodes[index] != "NULL")
			{
				root = new Treeode();
				//cout << "node created for element at index " << index << endl;

				int num = str2num(nodes[index]);
				root->data = num;

				//cout << root->data << endl;

				if(2*index+1 < (int)nodes.size())
					construct_tree(root->left, nodes, 2*index+1);

				if(2*index+2 < (int)nodes.size())
					construct_tree(root->right, nodes, 2*index+2);
			}
		}

		void print_inorder(Treeode *root)
		{
			if(root != NULL)
			{
				print_inorder(root->left);
				cout << root->data << " ";
				print_inorder(root->right);
			}

			else
				cout << "NULL ";
		}

		void print_preorder(Treeode *root)
		{
			if(root != NULL)
			{
				cout << root->data << " ";
				print_preorder(root->left);
				print_preorder(root->right);
			}

			else
				cout << "NULL ";
		}

		void print_postorder(Treeode *root)
		{
			if(root != NULL)
			{
				print_postorder(root->left);
				print_postorder(root->right);
				cout << root->data << " ";
			}

			else
				cout << "NULL ";
		}
};


Tree *input()
{
	int h;
	cin >> h;

	int n = exp2(h+1)-1;
	string s;
	vector<string> elements;

	for(int i=0; i<n; i++)
	{
		cin >> s;
		elements.push_back(s);
	}

	Tree *tree = new Tree();
	tree->construct_tree(tree->root, elements);

	return tree;
}