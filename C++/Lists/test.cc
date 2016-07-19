#include <iostream>
#include "list.h"
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

int main()
{
	List< pair<int,int> > *l = new List< pair<int,int> >();
	
	// char n = 'a'+5;
	// l->insert(n);

	// n = 'a'+3;
	// l->insert(n);

	// n = 'a'+1;
	// l->insert(n);

	// n = 'a'+4;
	// l->insert(n);

	// int a[] = {1,5,4,1,3,6};
	// l->construct(a, 6);

	vector< pair<int,int> > pairs;
	pairs.push_back(make_pair(1,2));
	pairs.push_back(make_pair(3,4));
	pairs.push_back(make_pair(5,6));

	l->construct(pairs);

	print(l);

	//cout << pairs[0] << endl;

	//l->print();

	// Node *ptr = l->head;
	// for(int i=0; i<20; i++)
	// {
	// 	cout << ptr->number << " ";
	// 	ptr = ptr->next;
	// }
	// cout << endl;

	l->clear();
	//l->print();
}