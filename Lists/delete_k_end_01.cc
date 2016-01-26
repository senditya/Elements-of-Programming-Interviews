#include <iostream>
#include "list.h"

using namespace std;

void removeFromEnd(List *list, int k)
{
	Node *ptr1 = list->head;

	for(int i=0; i<k; i++)
	{
		ptr1 = ptr1->next;
		//cout << ptr1->alpha << endl;
	}

	Node *ptr2 = list->head;

	if(ptr1 == NULL)
		list->head = (list->head)->next;

	else
	{
		while(ptr1->next != NULL)
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		ptr2->next = (ptr2->next)->next;
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

		removeFromEnd(list, k);

		list->print();
		cout << endl;
	}
}