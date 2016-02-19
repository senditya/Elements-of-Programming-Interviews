#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

struct truthTable
{
	vector<string> truth;
};

void initializeTables(vector<truthTable> &tables, int R, int C, int S)
{
	for(int i=0; i<S; i++)
	{
		for(int j=0; j<R; j++)
			tables[i].truth.push_back(string(C, -1));
	}
}

void getAdjacent(int R, int C, int r, int c, vector< pair<int, int> > &neighbors)
{
	if(r+1 < R)
		neighbors.push_back(make_pair(r+1,c));
	if(r-1 >= 0)
		neighbors.push_back(make_pair(r-1,c));
	if(c+1 < C)
		neighbors.push_back(make_pair(r, c+1));
	if(c-1 >= 0)
		neighbors.push_back(make_pair(r, c-1));
}

bool presence(int **grid, int *sequence, int r, int c, int start, int R, int C, int S, vector<truthTable> &tables)
{
	if(start == S)
		return true;

	else
	{
		if(tables[start].truth[r][c] != 0)
		{
			if(tables[start].truth[r][c] == 1)
				return true;

			else
			{
				if(grid[r][c] != sequence[start])
					tables[start].truth[r][c] = 0;

				else
				{
					//get neighboring cells
					vector< pair<int,int> > neighbors;
					getAdjacent(R, C, r, c, neighbors);

					//if any of them match string starting from start+1, set tables[start].truth[r][c] to 1
					//else, set tables[start].truth[r][c] to 0
					bool matches = false;

					for(int i=0; i<neighbors.size(); i++)
					{
						if(presence(grid, sequence, neighbors[i].first, neighbors[i].second, start+1, R,C,S, tables))
						{
							matches = true;
							break;
						}
					}

					if(matches)
						tables[start].truth[r][c] = 1;
					else
						tables[start].truth[r][c] = 0;
				}

				//according to value of tables[start].truth[r][c], return boolean
				if(tables[start].truth[r][c] == 1)
					return true;
				else
					return false;
			}
		}

		else
			return false;
	}
}

bool isPresent(int **grid, int *sequence, int R, int C, int S)
{
	if(S==0)
		return true;

	vector<truthTable> tables(S);
	initializeTables(tables, R, C, S);

	int i,j;
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
		{
			if(presence(grid, sequence, i, j, 0, R, C, S, tables))
				return true;
		}
	}

	return false;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int R,C;
		cin >> R >> C;

		int **grid;
		grid = (int **)malloc(R*sizeof(int *));
		for(int i=0; i<R; i++)
			grid[i] = (int *)malloc(C*sizeof(int));

		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
				cin >> grid[i][j];
		}

		int S;
		cin >> S;

		int sequence[S];
		for(int i=0; i<S; i++)
			cin >> sequence[i];

		if(isPresent(grid, sequence, R, C, S))
			cout << "PRESENT" << endl << endl;
		else
			cout << "ABSENT" << endl << endl;
	}
}