#include <iostream>
#include "list.h"

using namespace std;

void removeFromEnd(Node *node, int &k)
{
	if(node->next == NULL)
		k--;

	else
	{
		removeFromEnd(node->next, k);

		if(k == 0)
			node->next = (node->next)->next;

		k--;
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

		char a;

		List *list = new List();
		for(int i=0; i<n; i++)
		{
			cin >> a;
			list->insert(a);
		}

		list->print();

		int k;
		cin >> k;

		removeFromEnd(list->head, k);
		if(k == 0)
			list->head = (list->head)->next;

		list->print();
		cout << endl;
	}
}