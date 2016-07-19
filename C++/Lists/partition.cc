#include <iostream>
#include "list.h"

using namespace std;

void partition_epi(List *list, int k)
{
	Node *lesser_ptr=NULL, *equal_ptr=NULL, *greater_ptr = NULL;
	Node *lesser_head=NULL, *equal_head=NULL, *greater_head = NULL;
	Node *ptr = list->head;

	while(ptr != NULL)
	{
		if(ptr->number < k)
		{
			if(lesser_ptr == NULL)
			{
				lesser_ptr = ptr;
				lesser_head = ptr;
			}

			else
			{
				lesser_ptr->next = ptr;
				lesser_ptr = lesser_ptr->next;
			}
		}

		else if(ptr->number == k)
		{
			if(equal_ptr == NULL)
			{
				equal_ptr = ptr;
				equal_head = ptr;
			}

			else
			{
				equal_ptr->next = ptr;
				equal_ptr = equal_ptr->next;
			}
		}

		else
		{
			if(greater_ptr == NULL)
			{
				greater_ptr = ptr;
				greater_head = ptr;
			}

			else
			{
				greater_ptr->next = ptr;
				greater_ptr = greater_ptr->next;
			}
		}

		ptr = ptr->next;
	}

	if(lesser_head == NULL)
	{
		if(equal_head == NULL)
		{
			if(greater_head != NULL)
				greater_ptr->next = NULL;

			list->head = greater_head;
		}

		else
		{
			equal_ptr->next = greater_head;

			if(greater_head != NULL)
				greater_ptr->next = NULL;

			list->head = equal_head;
		}
	}

	else
	{
		lesser_ptr->next = equal_head;

		if(equal_head == NULL)
		{
			lesser_ptr->next = greater_head;

			if(greater_head != NULL)
				greater_ptr->next = NULL;

			list->head = lesser_head;
		}

		else
		{
			equal_ptr->next = greater_head;

			if(greater_head != NULL)
				greater_ptr->next = NULL;

			list->head = lesser_head;
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

		int k;
		cin >> k;

		list->print();

		cout << "Partitioning on " << k << ":" << endl;
		partition_epi(list, k);
		list->print();
		cout << endl;
	}
}