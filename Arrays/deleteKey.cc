#include <iostream>

using namespace std;

void removeKey(int *array, int &n, int key)
{
	int look_ahead = 0;
	int i=0;

	while(1)
	{
		while(i+look_ahead < n && array[i+look_ahead] == key)
			look_ahead++;

		if(i+look_ahead >= n)
			break;

		array[i] = array[i+look_ahead];

		i++;
	}

	n -= look_ahead;
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

		int key;
		cin >> key;

		print_array(array, n);
		removeKey(array, n, key);
		print_array(array, n);
	}
}