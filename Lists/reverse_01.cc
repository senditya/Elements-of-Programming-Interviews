#include <iostream>
#include "list.h"

using namespace std;

void print_list(Node *head)
{
	Node *ptr = head;

	while(ptr != NULL)
	{
		cout << ptr->alpha << " ";
		ptr = ptr->next;
	}

	cout << endl;
}

// Node *reverse(Node *past, Node *present)
// {
// 	if(present == NULL || present->next == NULL)
// 	{
// 		present->next = past;
// 		return present;
// 	}

// 	else
// 	{
// 		Node *future = present->next;
// 		present->next = past;

// 		return reverse(present, future);
// 	}
// }

Node *reverse(Node *past, Node *present)
{
	while(present->next != NULL)
	{
		Node *future = present->next;
		present->next = past;

		past = present;
		present = future;
	}

	present->next = past;
	return present;
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

		list->head = reverse(NULL, list->head);
		list->print();
	}
}