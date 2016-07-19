#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> &salaries)
{
	int n = (int)salaries.size();

	for(int i=0; i<n; i++)
		cout << salaries[i] << " ";
	cout << endl;
}

int find_cap(vector<int> &salaries, int	&threshold)
{
	int n = (int)salaries.size();

	sort(salaries.begin(), salaries.end());

	int sum = 0;

	int i;
	for(i=0; i<n; i++)
	{
		if(sum + salaries[i]*(n-i) > threshold)
			break;
		else
			sum += salaries[i];
	}

	if(i<n)
		return (threshold-sum)/(n-i);
	else
		return salaries[n-1];
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<int> salaries(n);
		for(int i=0; i<n; i++)
			cin >> salaries[i];

		int threshold;
		cin >> threshold;

		print_vector(salaries);

		int cap = find_cap(salaries, threshold);
		cout << cap << endl << endl;
	}
}