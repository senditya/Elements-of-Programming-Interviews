#include <iostream>
#include <vector>

using namespace std;

class Node
{
	public:
		int number;
		char alpha;
		string line;

		Node *next;
		Node *previous;
};

class List
{
	public:

		Node *head;
		int list_type;

		List()
		{
			head = NULL;
		}

		void clear()
		{
			Node *temp;

			while(head != NULL)
			{
				temp = head;
				head = head->next;

				delete temp;
			}
		}

		void insert(int n, bool circular = false)
		{
			list_type = 0;

			if(head == NULL)
			{
				head = new Node();
				head->number = n;
				head->next = NULL;

				if(circular)
					head->next = head;
			}

			else
			{
				Node *previous;
				Node *present;

				previous = head;
				present = head->next;

				while(present != NULL && present != head)
				{
					previous = present;
					present = present->next;
				}

				present = new Node();
				present->number = n;
				present->next = NULL;
				previous->next = present;

				if(circular)
					present->next = head;
			}
		}

		void insert(char a, bool circular = false)
		{
			list_type = 1;

			if(head == NULL)
			{
				head = new Node();
				head->alpha = a;
				head->next = NULL;

				if(circular)
					head->next = head;
			}

			else
			{
				Node *previous;
				Node *present;

				previous = head;
				present = head->next;

				while(present != NULL && present != head)
				{
					previous = present;
					present = present->next;
				}

				present = new Node();
				present->alpha = a;
				present->next = NULL;
				previous->next = present;

				if(circular)
					present->next = head;
			}
		}

		void insert(string s, bool circular = false)
		{
			list_type = 2;

			if(head == NULL)
			{
				head = new Node();
				head->line = s;
				head->next = NULL;

				if(circular)
					head->next = head;
			}

			else
			{
				Node *previous;
				Node *present;

				previous = head;
				present = head->next;

				while(present != NULL && present != head)
				{
					previous = present;
					present = present->next;
				}

				present = new Node();
				present->line = s;
				present->next = NULL;
				previous->next = present;

				if(circular)
					present->next = head;
			}
		}

		void print()
		{
			Node *present = head;

			cout << "START -> ";

			while(present != NULL)
			{
				switch(list_type)
				{
					case 0:	cout << present->number << " -> ";
							break;

					case 1: cout << present->alpha << " -> ";
							break;

					case 2:	cout << present->line << " -> ";
							break;
				}

				present = present->next;

				if(present == head)
					break;
			}

			if(present == NULL)
				cout << "END" << endl;
			else
				cout << "START" << endl;
		}

		void construct(int *array, int n, bool circular = false)
		{
			//clear();

			for(int i=0; i<n; i++)
				insert(array[i], circular);
		}

		void construct(char *array, int n, bool circular = false)
		{
			//clear();

			for(int i=0; i<n; i++)
				insert(array[i], circular);
		}

		void construct(string *array, int n, bool circular = false)
		{
			//clear();

			for(int i=0; i<n; i++)
				insert(array[i], circular);
		}

		void construct(vector<int> array, bool circular = false)
		{
			//clear();

			int n = (int)array.size();

			for(int i=0; i<n; i++)
				insert(array[i], circular);
		}

		void construct(vector<char> array, bool circular = false)
		{
			//clear();

			int n = (int)array.size();

			for(int i=0; i<n; i++)
				insert(array[i], circular);
		}

		void construct(vector<string> array, bool circular = false)
		{
			//clear();

			int n = (int)array.size();

			for(int i=0; i<n; i++)
				insert(array[i], circular);
		}
};