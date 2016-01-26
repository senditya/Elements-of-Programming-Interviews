#include <iostream>
#include "list.h"

using namespace std;

void merge(List *list1, List *list2, List *list)
{
	Node *ptr1 = list1->head;
	Node *ptr2 = list2->head;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->number < ptr2->number)
		{
			list->insert(ptr1->number);
			ptr1 = ptr1->next;
		}

		else
		{
			list->insert(ptr2->number);
			ptr2 = ptr2->next;
		}
	}

	if(ptr1 == NULL)
	{
		while(ptr2 != NULL)
		{
			list->insert(ptr2->number);
			ptr2 = ptr2->next;
		}
	}

	else
	{
		while(ptr1 != NULL)
		{
			list->insert(ptr1->number);
			ptr1 = ptr1->next;
		}
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

		List *list1 = new List();
		for(int i=0; i<n; i++)
		{
			cin >> x;
			list1->insert(x);
		}

		int m;
		cin >> m;

		List *list2 = new List();
		for(int i=0; i<m; i++)
		{
			cin >> x;
			list2->insert(x);
		}

		list1->print();
		list2->print();

		List *list = new List();

		merge(list1, list2, list);
		list->print();
	}
}