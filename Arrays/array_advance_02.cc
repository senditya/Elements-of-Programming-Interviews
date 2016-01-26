#include <iostream>
#include <vector>

using namespace std;

bool winnable(vector<int> &game)
{
	int n = game.size();
	int scope = 0;

	for(int i=0; i<n; i++)
	{
		if(i > scope)
			return false;

		if(i + game[i] > scope)
			scope = i + game[i];

		if(scope >= n-1)
			return true;
	}

	return false;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<int> game(n);

		for(int i=0; i<n; i++)
			cin >> game[i];

		cout << winnable(game) << endl;
	}
}