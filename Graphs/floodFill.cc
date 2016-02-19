#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void print_grid(vector< vector<bool> > &grid, int R, int C)
{
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			if(grid[i][j])
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

void getNeighbors(pair<int, int> start, vector< pair<int, int> > &neighbors, int R, int C)
{
	int r = start.first, c = start.second;

	if(c < C-1)
		neighbors.push_back(make_pair(r,c+1));
	if(r < R-1)
		neighbors.push_back(make_pair(r+1, c));
	if(r > 0)
		neighbors.push_back(make_pair(r-1, c));
	if(c > 0)
		neighbors.push_back(make_pair(r, c-1));
}

void flipColor(pair<int,int> start, bool color, vector< vector<bool> > &grid, int R, int C)
{
	queue< pair<int,int> > frontier;
	frontier.push(start);
	grid[start.first][start.second] = !grid[start.first][start.second];

	while(!frontier.empty())
	{
		pair<int,int> temp = frontier.front();
		frontier.pop();

		// grid[temp.first][temp.second] = !grid[temp.first][temp.second];
		// print_grid(grid, R, C);
		// char a;
		// cin >> a;

		vector< pair<int, int> > neighbors;
		getNeighbors(temp, neighbors, R, C);
		int m = (int)neighbors.size();

		for(int i=0; i<m; i++)
		{
			int r = neighbors[i].first, c = neighbors[i].second;

			if(grid[r][c] == color)
			{
				frontier.push(neighbors[i]);
				grid[r][c] = !grid[r][c];
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int R, C;
		cin >> R >> C;

		vector< vector<bool> > grid(R);
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				bool color;
				cin >> color;
				grid[i].push_back(color);
			}
		}

		cout << "ORIGINAL GRID:" << endl;
		print_grid(grid, R, C);
		cout << endl;

		int s;
		cin >> s;

		while(s--)
		{
			pair<int, int> start;
			cin >> start.first >> start.second;

			flipColor(start, grid[start.first][start.second], grid, R, C);

			cout << "AFTER FLIPPING COLORS STARTING FROM (" << start.first << "," << start.second << "):\n";
			print_grid(grid, R, C);
			cout << endl;
		}
	}
}