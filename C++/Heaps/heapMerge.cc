#include <iostream>
#include <vector>
#include <utility>
#include "heap.h"

using namespace std;

void print_vector(vector<int> &data)
{
	for(int i=0; i<(int)data.size(); i++)
			cout << data[i] << " ";
	cout << endl;
}

void heap_merge(vector< vector<int> > &stream, vector<int> &data)
{	
	int k = (int)stream.size();

	vector< pair<int,int> > elements(k);
	
	int counter[k];
	for(int i=0; i<k; i++)
	{
		counter[i] = 0;
		elements[i] = make_pair(stream[i][counter[i]], i);
	}

	Heap< pair<int,int> > heap;
	heap.build_heap(&elements, false);
	
	while(heap.size() > 0)
	{
		pair<int,int> min = heap.most_prior();
		heap.pop();

		data.push_back(min.first);

		int i = min.second;
		if( counter[i] < (int)stream[i].size()-1 )
		{
			counter[i]++;
			heap.push(make_pair(stream[i][counter[i]], i));
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int k;
		cin >> k;

		vector< vector<int> > stream(k);
		for(int i=0; i<k; i++)
		{
			int n;
			cin >> n;

			for(int j=0; j<n; j++)
			{
				int x;
				cin >> x;
				stream[i].push_back(x);
			}
		}

		vector<int> data;
		heap_merge(stream, data);

		print_vector(data);
		cout << endl;
	}
}