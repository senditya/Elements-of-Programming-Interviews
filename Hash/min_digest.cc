#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

void find_digest(vector<string> &array, vector<string> &set, int *digest)
{
	unordered_map<string,int> count;

	for(int i=0; i<(int)set.size(); i++)
		count[set[i]] = 0;

	int k=0, i, n = (int)array.size();
	unordered_map<string,int>::iterator it;
	string s;

	for(i=0; i<n; i++)
	{
		s = array[i];
		it = count.find(s);

		if(it != count.end())
		{
			if(count[s] == 0)
				k++;

			count[s] += 1;

			if(k == 1)
				digest[1] = i;

			if(k == (int)set.size())
			{
				digest[2] = i;
				break;
			}
		}
	}

	digest[0] = digest[2]-digest[1];
	int start=digest[1], end=digest[2];

	while(1)
	{
		s = array[start];
		it = count.find(s);

		if(it != count.end())
			count[s] -= 1;
		else
		{
			if(end-start)
		}

		start += 1;

		if(count[s] > 0)
			continue;
		else
		{
			while(end < n && array[end] != s)
				end++;

			if(end == n)
				break;
			else
			{
				count[s] += 1;

			}
		}
	}
}

int main()
{
	int t;
	cin >> t;

	string s;
	getline(cin, s);

	while(t--)
	{
		string s1;
		getline(cin, s1);

		stringstream ss(s1);
		vector<string> array
		while(!ss.eof())
		{
			ss >> s;
			array.push_back(s);
		}

		string s2;
		getline(cin, s2);

		ss(s2);
		vector<string> set;
		while(!ss.eof())
		{
			ss >> s;
			set.push_back(s);
		}

		int digest[3];
		find_digest(array, set, digest);

		cout << "ARRAY: " << s1 << endl;
		cout << "SET: " << s2 << endl;
		cout << "DIGEST: " << array.substr(digest[1], digest[0]) << endl << endl;
	}
}