#include <iostream>
#include "heap.h"
#include <vector>
#include <utility>

using namespace std;

template<typename T>
void print_vector(vector<T> v)
{
	for(int i=0; i<(int)v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void k_largest(vector<int> &input, int k, vector<int> &largest)
{
	Heap< pair<int,int> > heap;
	vector< pair<int,int> > elements;

	int n = (int)input.size();

	elements.push_back(make_pair(input[0], 0));
	heap.build_heap(&elements);

	while((int)largest.size() != k)
	{
		pair<int, int> max = heap.most_prior();
		heap.pop();

		largest.push_back(max.first);

		int i = max.second;
		if(LEFT(i) < n)
			heap.push(make_pair(input[LEFT(i)], LEFT(i)));
		if(RIGHT(i) < n)
			heap.push(make_pair(input[RIGHT(i)], RIGHT(i)));
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

		vector<int> input_heap(n);
		for(int i=0; i<n; i++)
			cin >> input_heap[i];

		int k;
		cin >> k;

		vector<int> largest;
		k_largest(input_heap, k, largest);

		print_vector(input_heap);
		cout << k << " largest elements:" << endl;
		print_vector(largest);
		cout << endl;
	}
}