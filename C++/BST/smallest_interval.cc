#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void print_array(vector<int> &array)
{
	int n = (int)array.size();

	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

void find_min_interval(vector< vector<int> > &arrays, int *interval)
{
	int ptrs[] = {0,0,0};
	int lengths[] = {(int)arrays[0].size(), (int)arrays[1].size(), (int)arrays[2].size()};

	int smallest, largest;

	while(1)
	{
		smallest = 0;
		largest = 0;

		for(int i=0; i<3; i++)
		{
			if(arrays[i][ptrs[i]] < arrays[smallest][ptrs[smallest]])
				smallest = i;
			if(arrays[i][ptrs[i]] > arrays[largest][ptrs[largest]])
				largest = i;
		}

		int candidate = arrays[largest][ptrs[largest]] - arrays[smallest][ptrs[smallest]];
		if(candidate < interval[0])
		{
			interval[0] = candidate;
			interval[1] = arrays[0][ptrs[0]];
			interval[2] = arrays[1][ptrs[1]];
			interval[3] = arrays[2][ptrs[2]];
		}

		if(ptrs[smallest] == lengths[smallest]-1)
			break;
		else
			ptrs[smallest]++;

	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n1,n2,n3;
		cin >> n1 >> n2 >> n3;

		vector<int> array1(n1), array2(n2), array3(n3);

		for(int i=0; i<n1; i++)
			cin >> array1[i];
		for(int i=0; i<n2; i++)
			cin >> array2[i];
		for(int i=0; i<n3; i++)
			cin >> array3[i];

		vector< vector<int> > arrays;
		arrays.push_back(array1);
		arrays.push_back(array2);
		arrays.push_back(array3);

		int interval[] = {INT_MAX, 0, 0, 0};
		find_min_interval(arrays, interval);

		print_array(array1);
		print_array(array2);
		print_array(array3);
		cout << "{" << interval[1] << "," << interval[2] << "," << interval[3] << "} : " << interval[0];
		cout << endl << endl;
	}
}