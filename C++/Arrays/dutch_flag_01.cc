#include <iostream>
#include <vector>

using namespace std;

void print_array(int *array, int n)
{
	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

void swap(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void partition(int *array, int n, int pivot)
{
	swap(array, 0, pivot);

	int i = 1, j = n-1;

	//print_array(array, n);

	while(i < j)
	{
		while(array[i] <= array[0] && i <= j)
			i++;

		while(array[j] > array[0] && j > i)
			j--;

		if(i < j)
			swap(array, i, j);

		//cout << "i = " << i << ", j = " << j << endl;
		//print_array(array, n);
	}

	swap(array, i-1, 0);
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

		int pivot;
		cin >> pivot;

		print_array(array, n);
		cout << "Pivot = " << array[pivot] << endl;

		partition(array, n, pivot);

		print_array(array, n);
	}
}