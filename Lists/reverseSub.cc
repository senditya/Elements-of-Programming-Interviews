#include <iostream>
#include "list.h"

using namespace std;

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

		List *list = new List();

		char a;
		for(int i=0; i<n; i++)
		{
			cin >> a;
			list->insert(a);
		}

		list->print();

		int start_ix, end_ix;
		cin >> start_ix >> end_ix;

		start_ix--; end_ix--;

		Node *start, *end;

		start = list->head;
		for(int i=0; i<start_ix; i++)
			start = start->next;

		end = list->head;
		for(int i=0; i<end_ix; i++)
			end = end->next;

		//cout << start->alpha << " " << end->alpha << endl;

		Node *postEnd = end->next;
		end->next = NULL;

		if(start_ix == 0)
			list->head = reverse(NULL, start);

		else
		{
			Node *preStart = list->head;

			for(int i=0; i<start_ix-1; i++)
				preStart = preStart->next;

			preStart->next = reverse(NULL, start);
		}

		Node *ptr;
		ptr = list->head;
		while(ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = postEnd;

		list->print();
	}
}