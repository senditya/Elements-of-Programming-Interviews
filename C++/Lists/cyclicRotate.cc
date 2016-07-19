#include <iostream>
#include "list.h"

using namespace std;

void rotate_right(List *list, int k)
{
	Node *ptr = list->head;

	if(ptr != NULL)
	{
		int n=1;

		while(ptr->next)
		{
			n++;
			ptr = ptr->next;
		}

		k = k%n;
		cout << "n = " << n << endl;

		ptr->next = list->head;

		ptr = list->head;
		for(int i=1; i<n-k; i++)
			ptr = ptr->next;

		list->head = ptr->next;
		ptr->next = NULL;
	}
}

void rotate_left(List *list, int k)
{
	Node *ptr = list->head;

	if(ptr != NULL)
	{
		int n=1;

		while(ptr->next)
		{
			n++;
			ptr = ptr->next;
		}

		ptr->next = list->head;

		k=k%n;

		if(k != 0)
		{
			ptr = list->head;

			for(int i=1; i<k; i++)
				ptr = ptr->next;

			list->head = ptr->next;
		}

		ptr->next = NULL;
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

		List *list = new List();
		int x;

		for(int i=0; i<n; i++)
		{
			cin >> x;
			list->insert(x);
		}

		int k;
		cin >> k;

		list->print();
		cout << k << endl;

		if(k > 0)
			rotate_right(list, k);
		else
			rotate_left(list, -k);

		list->print();
		cout << endl;
	}
}