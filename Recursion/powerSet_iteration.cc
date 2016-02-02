#include <iostream>

using namespace std;

int exp2(int n)
{
	int result=1;

	for(int i=0; i<n; i++)
		result *= 2;

	return result;
}

void print_sets(char *elements, int n)
{
	int max = exp2(n);
	int presence;
	string s;

	for(int i=0; i<max; i++)
	{
		presence = i;
		s = "";

		for(int j=0; j<n; j++)
		{
			bool include = (presence % 2)==1;
			presence /= 2;

			if(include)
				s = string(1, elements[n-1-j]) + s;
		}

		if(s == "")
			cout << "NULL" << endl;
		else
			cout << s << endl;
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

		char elements[n];
		for(int i=0; i<n; i++)
			cin >> elements[i];

		print_sets(elements, n);
		cout << endl;
	}
}