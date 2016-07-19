#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List *l = new List();
	
	// char n = 'a'+5;
	// l->insert(n);

	// n = 'a'+3;
	// l->insert(n);

	// n = 'a'+1;
	// l->insert(n);

	// n = 'a'+4;
	// l->insert(n);

	int a[] = {1,5,4,1,3,6};
	l->construct(a, 6);

	l->print();

	// Node *ptr = l->head;
	// for(int i=0; i<20; i++)
	// {
	// 	cout << ptr->number << " ";
	// 	ptr = ptr->next;
	// }
	// cout << endl;

	l->clear();
	l->print();
}