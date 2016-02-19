#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

void getNeighbors(pair<int, int> start, vector< pair<int, int> > &neighbors, int n)
{
	int r = start.first, c = start.second;

	if(c < n-1)
		neighbors.push_back(make_pair(r,c+1));
	if(r < n-1)
		neighbors.push_back(make_pair(r+1, c));
	if(r > 0)
		neighbors.push_back(make_pair(r-1, c));
	if(c > 0)
		neighbors.push_back(make_pair(r, c-1));
}

bool findPath(vector< vector<bool> > &maze, pair<int, int> start, pair<int, int> goal, vector< pair<int, int> > &path, vector< vector<bool> > &visited)
{
	visited[start.first][start.second] = true;

	if(start == goal)
		return true;

	else
	{
		int n = (int)maze.size();

		vector< pair<int, int> > neighbors;
		getNeighbors(start, neighbors, n);

		int m = (int)neighbors.size();

		for(int i=0; i<m; i++)
		{
			int r = neighbors[i].first, c = neighbors[i].second;

			if(maze[r][c] && !visited[r][c])
			{
				bool pathExists = findPath(maze, neighbors[i], goal, path, visited);

				if(pathExists)
				{
					path.insert(path.begin(), neighbors[i]);
					return true;
				}
			}
		}

		return false;
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

		vector< vector<bool> > maze(n);
		vector< vector<bool> > visited(n);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				bool pixel;
				cin >> pixel;
				maze[i].push_back(pixel);
				visited[i].push_back(false);
			}
		}

		pair<int,int> start;
		cin >> start.first >> start.second;
		pair<int, int> goal;
		cin >> goal.first >> goal.second;

		vector< pair<int,int> > path;
		bool pathExists = findPath(maze, start, goal, path, visited);

		if(!pathExists)
			cout << "NO PATH EXISTS" << endl;
		else
		{
			n = (int)path.size();

			cout << "PATH:" << endl;
			for(int i=0; i<n; i++)
				cout << "(" << path[i].first << "," << path[i].second << ") ";
			cout << endl;
		}
	}
}