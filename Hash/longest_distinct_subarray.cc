#include <iostream>
#include <unordered_map>

using namespace std;

int longest_distinct_substring(string &s)
{
	unordered_map<char, int> hash;

	int l = 1;
	int max = 1;
	int start = 0, end = 0;
	hash[s[0]] = 1;

	while(1)
	{
		end++;

		if(end == (int)s.size())
			break;

		if(hash[s[end]] == 0)
		{
			l++;
			end++;
			hash[s[end]] = 1;
		}

		else
		{
			if(l > max)
				max = l;

			while(s[start] != s[end])
			{
				hash[start] = 0;
				start++;
				l--;
			}

			start++;
		}
	}

	return max;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		int l = longest_distinct_substring(s);
		cout << s << endl;
		cout << l << endl << endl;
	}
}