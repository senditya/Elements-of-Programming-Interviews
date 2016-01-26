#include <iostream>
#include <vector>

using namespace std;

int calls = 0;

bool winnable(vector<int> &game, int start)
{
	calls++;
	int n = game.size();

	if(start == n-1)
		return true;

	else
	{
		int max_step = game[start];
		int i;

		for(i=1; i<=max_step; i++)
		{
			if(winnable(game, start+i))
				break;
		}

		if(i > max_step)
			return false;
		else
			return true;
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

		vector<int> game(n);

		for(int i=0; i<n; i++)
			cin >> game[i];

		cout << winnable(game, 0) << endl << calls << endl;
	}
}