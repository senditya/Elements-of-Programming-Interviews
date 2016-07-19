#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Node
{
	public:
		T data;

		Node *next;
		Node *previous;
};

template<typename T>
class List
{
	public:

		Node<T> *head;

		List()
		{
			head = NULL;
		}

		void clear()
		{
			Node<T> *temp;

			while(head != NULL)
			{
				temp = head;
				head = head->next;

				delete temp;
			}
		}

		void insert(T n, bool circular = false)
		{
			if(head == NULL)
			{
				head = new Node<T>();
				head->data = n;
				head->next = NULL;

				if(circular)
					head->next = head;
			}

			else
			{
				Node<T> *previous;
				Node<T> *present;

				previous = head;
				present = head->next;

				while(present != NULL && present != head)
				{
					previous = present;
					present = present->next;
				}

				present = new Node<T>();
				present->data = n;
				present->next = NULL;
				previous->next = present;

				if(circular)
					present->next = head;
			}
		}

		void print()
		{
			Node<T> *present = head;

			cout << "START -> ";

			while(present != NULL)
			{
				cout << present->data << " -> ";

				present = present->next;

				if(present == head)
					break;
			}

			if(present == NULL)
				cout << "END" << endl;
			else
				cout << "START" << endl;
		}

		void construct(T *array, int n, bool circular = false)
		{
			clear();

			for(int i=0; i<n; i++)
				insert(array[i], circular);
		}

		void construct(vector<T> array, bool circular = false)
		{
			clear();

			int n = (int)array.size();

			for(int i=0; i<n; i++)
				insert(array[i], circular);
		}
};