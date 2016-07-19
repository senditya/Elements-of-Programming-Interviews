#include <iostream>
#include <vector>

using namespace std;

int universal_sink(vector< vector<bool> > &adjMatrix)
{
	int n = adjMatrix.size();

	bool celebrity[n];
	for(int i=0; i<n; i++)
		celebrity[i] = true;

	for(int i=0; i<n; i++)
	{
		if(!celebrity[i])
			continue;

		for(int j=i+1; j<n; j++)
		{
			if(adjMatrix[i][j] == false)
				celebrity[j] = false;
			else
			{
				celebrity[i] = false;
				break;
			}
		}
	}

	for(int i=0; i<n; i++)
	{
		if(celebrity[i])
			return i;
	}

	return -1;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		bool knows;
		vector< vector<bool> > adjMatrix(n);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin >> knows;
				adjMatrix[i].push_back(knows);
			}
		}

		int sink = universal_sink(adjMatrix);
		cout << "UNIVERSAL SINK IS: " << sink << endl;
	}
}