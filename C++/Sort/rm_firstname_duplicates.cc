#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void print_names(vector< pair<string, string> > &names)
{
	int n = (int)names.size();

	for(int i=0; i<n; i++)
		cout << names[i].first << " " << names[i].second << endl;
}

void remove_first_duplicates(vector< pair<string, string> > &names, vector< pair<string, string> > &firsts)
{
	firsts.clear();

	sort(names.begin(), names.end());

	int n = (int)names.size();
	firsts.push_back(names[0]);
	int current = 0;

	for(int i=1; i<n; i++)
	{
		if(names[i].first != names[current].first)
		{
			firsts.push_back(names[i]);
			current = i;
		}
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

		vector< pair<string, string> > names;

		for(int i=0; i<n; i++)
		{
			string first, last;
			cin >> first >> last;
			names.push_back(make_pair(first, last));
		}

		print_names(names);

		cout << endl << "REMOVED IDENTICAL FIRST NAMES:" << endl;
		vector< pair<string, string> > firsts;
		remove_first_duplicates(names, firsts);

		print_names(firsts);
		cout << endl;
	}
}