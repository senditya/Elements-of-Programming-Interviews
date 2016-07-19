#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

template<typename T>
void print_vector(vector<T> &v)
{
	for(int i=0; i<(int)v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void get_medians(vector<int> &numbers, vector<float> &medians)
{
	medians.push_back(numbers[0]);
	medians.push_back((numbers[0]+numbers[1]+0.0)/2.0);

	Heap<int> min_heap, max_heap;
	vector<int> lower, upper;

	if(numbers[0] < numbers[1])
	{
		lower.push_back(numbers[0]);
		upper.push_back(numbers[1]);
	}

	else
	{
		lower.push_back(numbers[1]);
		upper.push_back(numbers[0]);
	}

	max_heap.build_heap(&lower);
	min_heap.build_heap(&upper, false);

	int n = 2;
	float median;

	for(int i=2; i<(int)numbers.size(); i++)
	{
		int element = numbers[i];

		if(n%2 == 0)
		{
			if(element > min_heap.most_prior())
			{
				int min = min_heap.most_prior();
				min_heap.pop();

				min_heap.push(element);
				max_heap.push(min);
			}

			else
				max_heap.push(element);

			median = max_heap.most_prior();
		}

		else
		{
			if(element > min_heap.most_prior())
				min_heap.push(element);

			else
			{
				int max = max_heap.most_prior();
				max_heap.pop();

				max_heap.push(element);
				min_heap.push(max);
			}

			median = (min_heap.most_prior() + max_heap.most_prior() + 0.0)/2.0;
		}

		medians.push_back(median);
		n++;
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

		vector<int> numbers(n);
		for(int i=0; i<n; i++)
			cin >> numbers[i];

		vector<float> medians;
		get_medians(numbers, medians);

		print_vector(numbers);
		print_vector(medians);
		cout << endl;
	}
}