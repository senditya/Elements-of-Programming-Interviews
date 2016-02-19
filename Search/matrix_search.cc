#include <iostream>
#include <vector>

using namespace std;

bool find_key(vector< vector<int> > &matrix, int key)
{
	int R = matrix.size();
	int C = matrix[0].size();

	//cout << R << " " << C << endl;

	int r=0, c=C-1;

	while(r < R && c >= 0)
	{
		//cout << r << " " << c << " " << matrix[r][c] << " : ";

		if(matrix[r][c] == key)
			return true;

		else if(matrix[r][c] < key)
			r++;

		else
			c--;
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
		cin >> R;
		cin >> C;

		vector< vector<int> > matrix(R);
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				int x;
				cin >> x;
				matrix[i].push_back(x);
			}
		}

		int key;
		cin >> key;
		//cout << key << endl;

		if(find_key(matrix, key))
			cout << "FOUND" << endl;
		else
			cout << "NOT FOUND" << endl;

	}
}