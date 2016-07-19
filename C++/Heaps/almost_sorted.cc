#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

void print_vector(vector<int> &numbers)
{
	for(int i=0; i<(int)numbers.size(); i++)
		cout << numbers[i] << " ";
	cout << endl;
}

void sort(vector<int> &numbers, int k)
{
	vector<int> elements;

	int i;
	for(i=0; i<=k; i++)
		elements.push_back(numbers[i]);

	Heap<int> heap;
	heap.build_heap(&elements, false);

	int j = 0;
	while(heap.size() > 0)
	{
		int min = heap.most_prior();
		numbers[j++] = min;
		heap.pop();

		if(i < (int)numbers.size())
			heap.push(numbers[i++]);
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

		vector<int> numbers;
		for(int i=0; i<n; i++)
		{
			int x;
			cin >> x;
			numbers.push_back(x);
		}

		int k;
		cin >> k;

		print_vector(numbers);

		sort(numbers, k);
		print_vector(numbers);
		cout << endl;
	}
}