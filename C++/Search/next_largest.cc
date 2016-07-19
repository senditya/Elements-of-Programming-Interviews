#include <iostream>
#include <vector>

using namespace std;

void print_array(int *array, int n)
{
	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

int next_largest(int *array, int n, int key)
{
	int x = key;
	int low = 0, high = n-1;

	while(low <= high)
	{
		int mid = low + (high-low)/2;

		if(array[mid] > key)
		{
			x = array[mid];
			high = mid-1;
		}

		else
			low = mid+1;
	}

	return x;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int array[n];
		for(int i=0; i<n; i++)
			cin >> array[i];

		int key;
		cin >> key;

		int larger = next_largest(array, n, key);

		print_array(array, n);

		if(larger != key)
			cout << larger << endl << endl;
		else
			cout << "NO ELEMENT LARGER THAN " << key << " IN ARRAY" << endl << endl;
	}
}