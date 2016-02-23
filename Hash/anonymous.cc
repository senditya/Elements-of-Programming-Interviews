#include <iostream>
#include <unordered_map>

using namespace std;

bool anonymous(string &letter, string &magazine)
{
	int m = (int)magazine.length(), n = (int)letter.length();

	unordered_map<char,int> hash;

	for(int i=0; i<m; i++)
	{
		if(magazine[i] != ' ')
		{
			// if(hash[magazine[i]] == 0)
			// 	hash[magazine[i]] = 1;
			// else
				hash[magazine[i]] += 1;
		}
	}

	for(int i=0; i<n; i++)
	{
		if(letter[i] != ' ')
		{
			if(hash[letter[i]] == 0)
				return false;
			else
				hash[letter[i]] -= 1;
		}
	}

	return true;
}

int main()
{
	int t;
	cin >> t;

	string s;
	getline(cin, s);

	while(t--)
	{
		string letter, magazine;
		getline(cin, magazine, '\n');
		getline(cin, letter, '\n');

		cout << "MAGAZINE: " << magazine << endl;
		cout << "LETTER: " << letter << endl;

		bool constructible = anonymous(letter, magazine);

		if(constructible)
			cout << "POSSIBLE" << endl;
		else
			cout << "NOT POSSIBLE" << endl;
	}
}