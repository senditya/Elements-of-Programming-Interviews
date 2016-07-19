#include <iostream>
#include <vector>

using namespace std;

void gray(vector<string> &codes, int n)
{
	if(n != 0)
	{
		if(n == 1)
		{
			codes.push_back("0");
			codes.push_back("1");
		}

		else
		{
			gray(codes, n-1);

			int sz = (int)codes.size();

			codes.insert(codes.end(), codes.rbegin(), codes.rend());

			for(int i=0; i<sz; i++)
				codes[i] = "0" + codes[i];
			for(int i=sz; i<2*sz; i++)
				codes[i] = "1" + codes[i];
		}
	}
}

void print_grayCodes(vector<string> &codes)
{
	int sz = (int)codes.size();

	for(int i=0; i<sz; i++)
		cout << codes[i] << " ";
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<string> codes;
		gray(codes, n);

		cout << "GRAY CODES OF LENGTH " << n << endl;
		print_grayCodes(codes);
		cout << endl;
	}
}