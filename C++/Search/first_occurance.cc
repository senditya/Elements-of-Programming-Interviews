#include <iostream>
#include <vector>

using namespace std;

int first_occurance(vector<int> &array, int key)
{
	int l=0, h=(int)array.size()-1, first=(int)array.size();

	while(l <= h)
	{
		int m = l + (h-l)/2;

		if(array[m] < key)
			l = m+1;

		else if(array[m] == key)
		{
			first = m;
			h = m-1;
		}

		else
			h = m-1;
	}

	return first;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<int> array(n);
		for(int i=0; i<n; i++)
			cin >> array[i];

		int k;
		cin >> k;

		int ix = first_occurance(array, k);
		if(ix < (int)array.size())
			cout << ix << endl << endl;
		else
			cout << "NOT FOUND" << endl << endl;
	}
}