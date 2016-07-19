#include <iostream>
#include <vector>

using namespace std;

int waysToReach(int distance, vector<int> &stoms, vector<int> &ways)
{
	if(distance < 0)
		return 0;

	if(distance == 0)
		return 1;

	else
	{
		if(ways[distance-1] == -1)
		{
			int sz = (int)stoms.size();

			int numberOfWays = 0;
			for(int i=0; i<sz; i++)
				numberOfWays += waysToReach(distance-stoms[i], stoms, ways);

			ways[distance-1] = numberOfWays;
		}

		return ways[distance-1];
	}
}

void print_vector(vector<int> &stoms)
{
	int n = (int)stoms.size();
	for(int i=0; i<n; i++)
		cout << stoms[i] << " ";
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

		vector<int> stoms(n);
		for(int i=0; i<n; i++)
			cin >> stoms[i];

		int distance;
		cin >> distance;

		vector<int> ways(distance, -1);

		int numberOfWays = waysToReach(distance, stoms, ways);

		cout << "ATOMIC STEPS:" << endl;
		print_vector(stoms);

		cout << "NUMBER OF WAYS TO REACH A DISTANCE " << distance << " = " << numberOfWays << endl;

		cout << "DISTANCE MAP:" << endl;
		for(int i=0; i<distance; i++)
			cout << i+1 << ":" << ways[i] << endl;
		cout << endl;
	}
}