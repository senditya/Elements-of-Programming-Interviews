#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &array)
{
	int n = (int)array.size();

	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

void find_intersection(vector<int> &set1, vector<int> &set2, vector<int> &intersect)
{
	int n1 = (int)set1.size(), n2 = (int)set2.size();
	int ptr1=0, ptr2=0;

	vector<int> set;

	while(ptr1<n1 && ptr2<n2)
	{
		if(set1[ptr1] == set2[ptr2])
		{
			set.push_back(set1[ptr1]);
			ptr1++;
			ptr2++;
		}

		else if(set1[ptr1] > set2[ptr2])
			ptr2++;

		else
			ptr1++;
	}

	int n = (int)set.size();
	int current = set[0];
	intersect.push_back(current);

	for(int i=1; i<n; i++)
	{
		if(set[i] != current)
		{
			current = set[i];
			intersect.push_back(current);
		}
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

		vector<int> set1(n1);
		vector<int> set2(n2);

		for(int i=0; i<n1; i++)
			cin >> set1[i];
		for(int i=0; i<n2; i++)
			cin >> set2[i];

		vector<int> intersect;
		find_intersection(set1, set2, intersect);

		print_vector(set1);
		print_vector(set2);
		cout << "INTERSECTION: ";
		print_vector(intersect);
		cout << endl;
	}
}