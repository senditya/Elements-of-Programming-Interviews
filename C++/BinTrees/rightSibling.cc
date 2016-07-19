#include <iostream>
#include "tree.h"

using namespace std;

void print_bfs(Tree *tree)
{
	Treeode *level_start = tree->root, *temp;
	int i=0;

	while(level_start != NULL)
	{
		cout << "LEVEL " << i <<": ";

		temp = level_start;
		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->level_next;
		}

		cout << endl;

		level_start = level_start->left;
		i++;
	}
}

void connect(Treeode *root)
{
	if(root != NULL)
	{
		if(root->left)
		{
			connect(root->left);
			connect(root->right);
		}

		Treeode *temp_l, *temp_r;
		temp_l = root->left;
		temp_r = root->right;

		while(temp_l != NULL)
		{
			temp_l->level_next = temp_r;
			temp_l = temp_l->right;
			temp_r = temp_r->left;
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Tree *tree = input();

		connect(tree->root);

		print_bfs(tree);
	}
}