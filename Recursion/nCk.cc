#include <iostream>
#include <vector>

using namespace std;

void print_combinations(vector<string> &choices)
{
	int n = (int)choices.size();
	for(int i=0; i<n; i++)
		cout << choices[i] << " ";
	cout << endl;
}

void combine(string &elements, int k, vector<string> &choices, int start=0)
{
	if(k == 0)
		choices.push_back("");

	else
	{
		if(k == elements.length() - start)
		{
			string s = "";
			for(int i=0; i<k; i++)
				s = string(1, elements[i+start]) + s;
			choices.push_back(s);
		}

		else
		{
			combine(elements, k, choices, start+1);
			int n = (int)choices.size();

			combine(elements, k-1, choices, start+1);

			int m = (int)choices.size();
			
			for(int i=n; i<m; i++)
				choices[i] = string(1, elements[start]) + choices[i];
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

		string elements(n, '\0');

		for(int i=0; i<n; i++)
			cin >> elements[i];

		int k;
		cin >> k;

		vector<string> choices;
		combine(elements, k, choices);

		cout << string(elements) << endl;
		cout << k << endl;

		n = (int)choices.size();
		for(int i=0; i<n; i++)
			cout << choices[i] << endl;
		cout << endl;
	}
}