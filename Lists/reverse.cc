#include <iostream>
#include "list.h"

using namespace std;

void swap(Node *start, Node *end)
{
	char temp = end->alpha;
	end->alpha = start->alpha;
	start->alpha = temp;
}

Node *reverse(Node *start, Node *end, bool &startB4end)
{
	if(end->next == NULL)
	{
		cout << "1. Swapping " << start->alpha << " " << end->alpha << endl;
		swap(start, end);
		return start->next;
	}

	else
	{
		start = reverse(start, end->next, startB4end);

		if(start == end || start == end->next)
			startB4end = false;

		if(startB4end)
		{
			cout << "2. Swapping " << start->alpha << " " << end->alpha << endl;
			swap(start, end);
		}

		return start->next;
	}
}

void reverse_list(List *list)
{
	if(list->head != NULL)
	{
		if(list->head->next != NULL)
		{
			Node *start = list->head;
			Node *end = start->next;

			bool startB4end = true;
			reverse(start, end, startB4end);
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

		char a;

		List *list = new List();

		for(int i=0; i<n; i++)
		{
			cin >> a;
			list->insert(a);
		}

		list->print();

		reverse_list(list);
		list->print();
	}
}