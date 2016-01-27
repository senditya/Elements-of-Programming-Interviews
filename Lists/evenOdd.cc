#include <iostream>
#include "list.h"

using namespace std;

void evenOdd(List *list)
{
	if(list->head != NULL)
	{
		List *even = new List(), *odd = new List();

		even->head = list->head;
		odd->head = (list->head)->next;

		if(odd->head != NULL)
		{
			Node *ptr = (odd->head)->next;
			Node *even_ptr = even->head, *odd_ptr = odd->head;

			while(ptr != NULL && ptr->next != NULL)
			{
				even_ptr->next = ptr;
				odd_ptr->next = ptr->next;

				ptr = (ptr->next)->next;
				even_ptr = even_ptr->next;
				odd_ptr = odd_ptr->next;
			}

			if(ptr == NULL)
			{
				even_ptr->next = odd->head;
				odd_ptr->next = NULL;
			}

			else
			{
				even_ptr->next = ptr;
				(even_ptr->next)->next = odd->head;
				odd_ptr->next = NULL;
			}
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

		List *list = new List();
		for(int i=0; i<n; i++)
		{
			cin >> x;
			list->insert(x);
		}

		list->print();

		evenOdd(list);

		list->print();
		cout << endl;
	}
}