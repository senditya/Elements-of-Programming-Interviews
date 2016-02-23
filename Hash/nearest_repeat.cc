#include <iostream>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

pair<int,int> nearest_repeat(vector<string> &doc)
{
	unordered_map<string, int> hash;
	int n = (int)doc.size();

	pair<int,int> stats = make_pair(-1, n+1);

	for(int i=0; i<n; i++)
	{
		string s = doc[i];

		if(hash[s] == 0)
			hash[s] = i+1;

		else
		{
			if(stats.second > i+1-hash[s])
			{
				stats.first = hash[s]-1;
				stats.second = i+1-hash[s];
			}

			hash[s] = i+1;
		}
	}

	return stats;
}

int main()
{
	int t;
	cin >> t;

	string s;
	getline(cin,s);

	while(t--)
	{
		getline(cin, s);

		stringstream ss(s);
		vector<string> doc;

		string s1;
		while(!ss.eof())
		{
			ss >> s1;
			doc.push_back(s1);
		}

		pair<int, int> nearest = nearest_repeat(doc);
		cout << s << endl;
		if(nearest.first != -1)
			cout << doc[nearest.first] << " : (" << nearest.first << "," << nearest.first+nearest.second << ")";
		else
			cout << "NO REPETITION";
		cout << endl << endl;
	}
}