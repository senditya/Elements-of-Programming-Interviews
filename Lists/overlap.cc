#include <iostream>
#include "list.h"
#include <ctime>

using namespace std;

bool joinOrNot(List *list1, List *list2)
{
	bool joined = (rand()%2 == 0);

	if(joined)
	{
		int n1=0, n2=0;
		for(Node *ptr = list1->head; ptr != NULL; ptr=ptr->next, n1++);
		for(Node *ptr = list2->head; ptr != NULL; ptr=ptr->next, n2++);

		int m1 = rand()%n1, m2 = rand()%n2;
		Node *ptr1=list1->head, *ptr2=list2->head;

		cout << m1 << " " << m2 << " : ";
		
		for(int i=0; i<m1; i++)
			ptr1=ptr1->next;
		for(int i=0; i<m2; i++)
			ptr2=ptr2->next;

		bool stream_list = (rand()%2 == 0);
		cout << stream_list << endl;

		if(stream_list)
			ptr1->next = ptr2;
		else
			ptr2->next = ptr1;
	}

	return joined;
}

Node *findJoint(List *list1, List *list2)
{
	int n1=0, n2=0;

	for(Node *ptr=list1->head; ptr != NULL; ptr=ptr->next, n1++);
	for(Node *ptr=list2->head; ptr != NULL; ptr=ptr->next, n2++);

	int n_l, n_L;
	List *larger, *smaller;

	if(n1 > n2)
	{
		larger = list1; smaller = list2;
		n_L = n1; n_l = n2;
	}

	else
	{
		larger = list2; smaller = list1;
		n_L = n2; n_l = n1;
	}

	Node *ptr1 = larger->head, *ptr2 = smaller->head;
	for(int i=0; i<n_L-n_l; i++)
		ptr1 = ptr1->next;

	while(ptr1 != NULL)
	{
		if(ptr1 == ptr2)
			break;

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	return ptr1;
}

void print_list(Node *start)
{
	while(start->next != NULL)
	{
		cout << start->alpha << " -> ";
		start = start->next;
	}
	cout << start->alpha << endl;
}


int main()
{
	int t;
	cin >> t;

	srand(time(NULL));

	while(t--)
	{
		int n1,n2;
		char a;

		cin >> n1;
		List *list1 = new List();
		for(int i=0; i<n1; i++)
		{
			cin >> a;
			list1->insert(a);
		}

		cin >> n2;
		List *list2 = new List();
		for(int i=0; i<n2; i++)
		{
			cin >> a;
			list2->insert(a);
		}

		bool joined = joinOrNot(list1, list2);

		cout << joined << endl;
		list1->print();
		list2->print();

		Node *join = findJoint(list1, list2);

		if(join == NULL)
			cout << "Lists are separate" << endl;
		else
		{
			cout << "Joined component is:" << endl;
			print_list(join);
		}
	}
}