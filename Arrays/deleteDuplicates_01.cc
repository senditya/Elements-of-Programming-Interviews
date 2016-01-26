#include <iostream>

using namespace std;

void delete_duplicates(int *array, int &n)
{
	int i=1, j=1;
	int prev_int = array[0];

	while(j < n)
	{
		while(array[j] == prev_int && j<n)
			j++;

		if(j == n)
			break;

		prev_int = array[j];
		array[i] = array[j];

		i++;
		j++;
	}

	n -= (j-i);
}

void print_array(int *array, int n)
{
	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
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
		delete_duplicates(array, n);
		print_array(array, n);
	}
}