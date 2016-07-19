#include <iostream>

using namespace std;

void print_array(int *array, int n)
{
	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

int find_min(int *array, int n)
{
	int low = 0, high = n-1;

	while(low < high)
	{
		int mid = low + (high-low)/2;
		
		if(array[mid] > array[high])
			low = mid+1;
		else
			high = mid;
	}

	return low;
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

		print_array(array, n);
		int min = find_min(array, n);
		if(min >= 0)
			cout << "MINIMUM ELEMENT IS: " << array[min] << endl << endl;
		else
			cout << "ALGO FAILED" << endl << endl;
	}
}