#include <iostream>
#include <vector>

using namespace std;

void print_nextRow(vector<int> &previous)
{
	int n = (int)previous.size();

	vector<int> present;
	cout << "1 ";
	present.push_back(1);

	int i = 0, j;

	for(j=1; j<n; j++, i++)
	{
		present.push_back(previous[i] + previous[j]);
		cout << previous[i] + previous[j] << " ";
	}

	present.push_back(1);
	cout << "1" << endl;

	previous.clear();
	n = (int)present.size();

	for(i=0; i<n; i++)
		previous.push_back(present[i]);
}

void print_pascal(int n)
{
	cout << "First " << n << " row(s) of Pascal\'s triangle is(are):" << endl << endl;

	if(n == 1)
		cout << "1" << endl << endl;

	else if(n == 2)
		cout << "1" << endl << "1 1" << endl << endl;

	else
	{
		cout << "1" << endl << "1 1" << endl;

		vector<int> previous (2,1);

		for(int i=2; i<n; i++)
			print_nextRow(previous);

		cout << endl;
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

		print_pascal(n);
	}
}