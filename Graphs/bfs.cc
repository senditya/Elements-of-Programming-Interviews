#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs_traversal(vector< vector<int> > &adjMatrix, vector<int> &bfs, int start=0)
{
	queue<int> front;
	front.push(start);

	int n = (int)adjMatrix.size();
	bool visited[n];
	for(int i=0; i<n; i++)
		visited[i] = false;
	visited[start] = true;

	while(!front.empty())
	{
		int temp = front.front();
		front.pop();
		bfs.push_back(temp);

		for(int i=0; i<n; i++)
		{
			if(adjMatrix[temp][i] != 0 && !visited[i])
			{
				front.push(i);
				visited[i] = true;
			}
		}
	}
}

void print_vector(vector<int> &bfs)
{
	int n = (int)bfs.size();
	for(int i=0; i<n; i++)
		cout << bfs[i] << " ";
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

		int x;
		vector< vector<int> > adjMatrix(n);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin >> x;
				adjMatrix[i].push_back(x);
			}
		}

		vector<int> bfs;
		bfs_traversal(adjMatrix, bfs);

		cout << "BFS traversal is:" << endl;
		print_vector(bfs);
		cout << endl;
	}
}