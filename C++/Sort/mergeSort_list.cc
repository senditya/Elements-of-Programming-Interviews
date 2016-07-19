#include <iostream>
#include <vector>
#include "../Lists/list.h"
#include <utility>

using namespace std;

void print(List< pair<int,int> > *l)
{
	Node< pair<int,int> > *ptr = l->head;

	cout << "START -> ";

	while(ptr != NULL)
	{
		cout << "(" << (ptr->data).first << "," << (ptr->data).second << ") -> ";
		ptr = ptr->next;
	}

	cout << "END" << endl;
}

Node< pair<int,int> > *merge_sort(Node< pair<int,int> > *head)
{
	if(head == NULL || head->next == NULL)
		return head;

	else
	{
		Node< pair<int,int> > *slow, *fast;

		slow = head;
		fast = head;

		while(fast->next != NULL && fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		Node< pair<int,int> > *head1, *head2;

		head1 = head;
		head2 = slow->next;

		slow->next = NULL;

		head1 = merge_sort(head1);
		head2 = merge_sort(head2);

		Node< pair<int,int> > *ptr;
		if((head2->data).first < (head1->data).first)
		{
			ptr = head2;
			head2 = head2->next;
		}
		else
		{
			ptr = head1;
			head1 = head1->next;
		}

		head = ptr;

		while(head1 != NULL && head2 != NULL)
		{
			if((head2->data).first < (head1->data).first)
			{
				ptr->next = head2;
				ptr = ptr->next;
				head2 = head2->next;
			}

			else
			{
				ptr->next = head1;
				ptr = ptr->next;
				head1 = head1->next;
			}
		}

		if(head1 != NULL)
		{
			while(head1 != NULL)
			{
				ptr->next = head1;
				ptr = ptr->next;
				head1 = head1->next;
			}
		}

		if(head2 != NULL)
		{
			while(head2 != NULL)
			{
				ptr->next = head2;
				ptr = ptr->next;
				head2 = head2->next;
			}
		}

		return head;
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

		List< pair<int,int> > *list = new List< pair<int,int> >();
		
		pair<int,int> element;
		for(int i=0; i<n; i++)
		{
			cin >> element.first >> element.second;
			list->insert(element);
		}

		print(list);

		list->head = merge_sort(list->head);
		print(list);
		cout << endl;
	}
}