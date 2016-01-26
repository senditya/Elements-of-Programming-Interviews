#include <iostream>

using namespace std;

void print_array(char *array, int n)
{
	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

int findStart(int *ordering, int n)
{
	for(int i=0; i<n; i++)
	{
		if(ordering[i] >= 0)
			return i;
	}

	return -1;
}

void permute(char *array, int n, int *ordering)
{
	char stand_by;
	int start;
	int new_position, old_position;

	for(int i=0; i<n; i++)
	{
		if(ordering[i] == i)
			ordering[i] -= n;
	}

	start = findStart(ordering, n);

	while(start != -1)
	{
		new_position = ordering[start];
		int ordering_ix = start;
		stand_by = array[start];

		while(new_position != start)
		{
			char temp = array[new_position];
			array[new_position] = stand_by;
			stand_by = temp;

			ordering[ordering_ix] -= n;
			ordering_ix = new_position;
			new_position = ordering[ordering_ix];
		}

		array[new_position] = stand_by;
		ordering[ordering_ix] -= n;

		start = findStart(ordering, n);
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

		int ordering[n];
		char array[n];

		for(int i=0; i<n; i++)
			cin >> array[i];
		for(int i=0; i<n; i++)
			cin >> ordering[i];

		permute(array, n, ordering);

		cout << "Permuted array is:" << endl;
		print_array(array, n);
		cout << endl;
	}
}