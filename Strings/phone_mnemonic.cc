#include <iostream>
#include <cstring>

using namespace std;


bool next(int *counter, string &phone, int *limits)
{
	int n = phone.length();
	int ix = n-1;

	while(ix >= 0)
	{
		if(counter[ix] < limits[phone[ix]])
		{
			counter[ix] += 1;
			break;
		}

		else
		{
			counter[ix] = 0;
			ix--;
		}
	}

	if(ix < 0)
		return false;
	else
		return true;
}


void print_mnemonics(string &phone, string *keypad, int *limits)
{
	int n = phone.length();
	int counter[n];
	memset(counter, 0, 4*n);
	
	do
	{
		bool finish = true;

		for(int i=0; i<n; i++)
			cout << keypad[phone[i]][counter[i]];

		cout << endl;

	} while(next(counter, phone, limits));
}


int main()
{
	int t;
	cin >> t;

	string keypad[10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
	int limits[10];
	for(int i=0; i<10; i++)
		limits[i] = keypad[i].length()-1;

	while(t--)
	{
		string phone;
		cin >> phone;

		for(int i=0; i<phone.length(); i++)
			phone[i] -= '0';

		print_mnemonics(phone, keypad, limits);
	}
}