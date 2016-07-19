#include <iostream>
#include <vector>

using namespace std;

void getSets(char *elements, int size, vector<string> &set, int start=0)
{
	if(start == size)
		set.push_back("");

	else
	{
		getSets(elements, size, set, start+1);
		int n = (int)set.size();

		set.insert(set.end(), set.begin(), set.end());

		for(int i=0; i<n; i++)
			set[i] = string(1, elements[start]) + set[i];
	}
}

void print_sets(vector<string> &set)
{
	int n = (int)set.size();

	for(int i=0; i<n; i++)
	{
		if(set[i] != "")
			cout << set[i] << endl;
		else
			cout << "NULL" << endl;
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

		char elements[n];
		for(int i=0; i<n; i++)
			cin >> elements[i];

		vector<string> set;
		getSets(elements, n, set);

		print_sets(set);
		cout << endl;
	}
}