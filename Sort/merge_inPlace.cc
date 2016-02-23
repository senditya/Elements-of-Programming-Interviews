#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &array, int n)
{
	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

void merge(vector<int> &array1, vector<int> &array2)
{
	int n2 = (int)array2.size();
	int n1 = (int)array1.size()-n2;

	for(int i=0; i<n1; i++)
		array1[n2+i] = array1[i];

	int ptr1 = n2, ptr2 = 0, ptr = 0;

	while(ptr1 != n1+n2 && ptr2 != n2)
	{
		if(array1[ptr1] < array2[ptr2])
		{
			array1[ptr] = array1[ptr1];
			ptr1++;
			ptr++;
		}

		else
		{
			array1[ptr] = array2[ptr2];
			ptr2++;
			ptr++;
		}
	}

	while(ptr1 != n1+n2)
	{
		array1[ptr] = array1[ptr1];
		ptr1++;
		ptr++;
	}

	while(ptr2 != n2)
	{
		array1[ptr] = array2[ptr2];
		ptr2++;
		ptr++;
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n1,n2;
		cin >> n1 >> n2;

		vector<int> array1(n1+n2);
		vector<int> array2(n2);

		for(int i=0; i<n1; i++)
			cin >> array1[i];
		for(int i=0; i<n2; i++)
			cin >> array2[i];

		print_vector(array1, n1);
		print_vector(array2, n2);

		merge(array1, array2);

		cout << "MERGED: ";
		print_vector(array1, n1+n2);
		cout << endl;
	}
}