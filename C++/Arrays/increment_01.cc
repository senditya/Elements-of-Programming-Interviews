#include <iostream>
#include <string>

using namespace std;

string increment(string s)
{
	int n = s.length();
	int i = n-1;
	int carry = 0;

	if(s[i] == '9')
	{
		s[i] = '0';
		carry = 1;
	}

	else
		s[i] += 1;

	i--;

	while(carry != 0 && i >= 0)
	{
		if(s[i] == '9')
		{
			s[i] = '0';
			carry = 1;
		}

		else
		{
			s[i] += 1;
			carry = 0;
		}

		i--;
	}

	if(i < 0)
		s = "1" + s;

	return s;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		cout << s << endl;
		cout << increment(s) << endl << endl;
	}
}