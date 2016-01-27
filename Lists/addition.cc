#include <iostream>
#include "list.h"

using namespace std;

List *add(List *list1, List *list2)
{
	List *list = new List();
	Node *ptr1 = list1->head, *ptr2 = list2->head;
	int carry = 0;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		int x = ptr1->number + ptr2->number + carry;

		carry = x/10;
		x = x%10;

		list->insert(x);

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	if(ptr1 != NULL)
	{
		int x = ptr1->number + carry;

		carry = x/10;
		x = x%10;

		list->insert(x);

		ptr1 = ptr1->next;
	}

	if(ptr2 != NULL)
	{
		int x = ptr2->number + carry;

		carry = x/10;
		x = x%10;

		list->insert(x);

		ptr2 = ptr2->next;
	}

	if(carry != 0)
		list->insert(carry);

	return list;
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

		List *list1 = new List();
		for(int i=0; i<n; i++)
		{
			cin >> a;
			list1->insert((int)(a-'0'));
		}

		cin >> n;

		List *list2 = new List();
		for(int i=0; i<n; i++)
		{
			cin >> a;
			list2->insert((int)(a-'0'));
		}

		List *list = add(list1, list2);

		list1->print();
		list2->print();
		list->print();
		cout << endl;
	}
}