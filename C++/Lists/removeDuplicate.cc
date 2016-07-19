#include <iostream>
#include "list.h"

using namespace std;

void removeDuplicates(List *list)
{
	Node *ptr = list->head;

	while(ptr != NULL && ptr->next != NULL)
	{
		Node *ptr2 = ptr->next;

		while(ptr2 != NULL && ptr2->number == ptr->number)
			ptr2 = ptr2->next;

		ptr->next = ptr2;
		ptr = ptr->next;
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

		int x;
		List *list = new List();

		for(int i=0; i<n; i++)
		{
			cin >> x;
			list->insert(x);
		}

		list->print();

		removeDuplicates(list);
		list->print();
		cout << endl;
	}
}