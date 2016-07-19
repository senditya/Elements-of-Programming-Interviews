#include <iostream>
#include "list.h"

using namespace std;

bool pair_check(Node *&start, Node *end)
{
	if(end->next != NULL)
	{
		if(pair_check(start, end->next))
		{	
			//cout << start->alpha << " " << end->alpha << endl;
			if(start->alpha == end->alpha)
			{
				start = start->next;
				return true;
			}

			else
				return false;
		}

		else
			return false;
	}

	else
	{
		//cout << start->alpha << " " << end->alpha << endl;
		if(start->alpha == end->alpha)
		{
			start = start->next;
			return true;
		}

		else
			return false;
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

		Node *start = list->head;
		bool is_palindrome = pair_check(start, start);

		list->print();

		if(is_palindrome)
			cout << "PALINDROME" << endl << endl;
		else
			cout << "NOT PALINDROME" << endl << endl;
	}
}