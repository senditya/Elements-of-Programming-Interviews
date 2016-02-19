#include <iostream>
#include "tree.h"

using namespace std;

void tree2dll(Treeode *&root, Treeode *&head, Treeode *&tail)
{
	if(root == NULL)
	{
		head = NULL;
		tail = NULL;
	}

	else
	{
		Treeode *right_head, *left_tail;

		tree2dll(root->left, head, left_tail);
		tree2dll(root->right, right_head, tail);

		if(head == NULL)
			head = root;
		else
		{
			left_tail->next = root;
			root->prev = left_tail;
		}

		if(right_head == NULL)
			tail = root;
		else
		{
			root->next = right_head;
			right_head->prev = root;
		}
	}
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

		tree->print_inorder(tree->root);
		cout << endl;

		Treeode *head, *tail;
		tree2dll(tree->root, head, tail);

		cout << "DLL: first forward and then back:" << endl;
		Treeode *ptr;

		for(ptr = head; ptr != tail; ptr = ptr->next)
			cout << ptr->data << " ";
		cout << ptr->data << endl;

		for(ptr = tail; ptr != head; ptr = ptr->prev)
			cout << ptr->data << " ";
		cout << ptr->data << endl;
		cout << endl;
	}
}