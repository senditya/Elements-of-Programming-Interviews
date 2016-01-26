#include <iostream>
#include "list.h"

using namespace std;

void evenOdd(List *list, List *even, List *odd)
{
	if(list->head != NULL)
	{
		even->head = list->head;
		odd->head = (list->head)->next;

		if(odd->head != NULL)
		{
			Node *ptr = (odd->head)->next;
			Node *even_ptr = even->head, *odd_ptr = odd->head;

			
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


		List *even = new List(), *odd = new List();
		evenOdd(list, even, odd);

		list->print();
		even->print();
		odd->print();
		cout << endl;
	}
}