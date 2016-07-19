#include <iostream>
#include <vector>
#include <unordered_map>
#include "../Heaps/heap.h"
#include <utility>

using namespace std;

void print_k_frequent(vector<string> &doc, int k)
{
	int n = (int)doc.size();
	unordered_map<string, int> hash;

	for(int i=0; i<n; i++)
		hash[doc[i]] += 1;

	vector< pair<int,string> > elements;
	unordered_map<string, int>::iterator it;
	int i;

	for(it = hash.begin(), i=0; it != hash.end(); it++, i++)
	{
		if(i == k)
			break;

		elements.push_back(make_pair(it->second,it->first));
	}

	Heap< pair<int, string> > heap;
	heap.build_heap(&elements, false);

	for(; it != hash.end(); it++)
	{
		if(it->second > heap.most_prior().first)
		{
			heap.pop();
			heap.push(make_pair(it->second, it->first));
		}
	}

	for(i=0; i<k; i++)
		cout << elements[i].second << " : " << elements[i].first << endl;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<string> doc(n);
		for(int i=0; i<n; i++)
			cin >> doc[i];

		int k;
		cin >> k;

		print_k_frequent(doc, k);
		cout << endl;
	}
}