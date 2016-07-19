#include <iostream>
#include "list.h"
#include <ctime>

using namespace std;

bool cyclicTest(List *list)
{
	Node *start = list->head;
	Node *ptr = start->next;

	while(1)
	{
		if(ptr == start)
			return true;

		else if(ptr == NULL)
			return false;

		else
			ptr = ptr->next;
	}
}

int main()
{
	int t;
	cin >> t;

	srand(time(NULL));

	while(t--)
	{
		int n;
		cin >> n;

		List *list = new List();
		bool cyclic = (rand()%2 == 0);
		cout << cyclic << endl;

		char a;

		for(int i=0; i<n; i++)
		{
			cin >> a;
			list->insert(a, cyclic);
		}

		list->print();

		if(cyclicTest(list))
			cout << "CIRCULAR LIST" << endl << endl;
		else
			cout << "LINEAR LIST" << endl << endl;
	}
}