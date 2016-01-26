#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		unsigned long long int x, y;
		cin >> x;

		int ones = 0;

		while(x != 0)
		{
			ones++;

			x &= (x-1);
		}

		cout << "#1's = " << ones << " , Parity = " << ones%2 << endl;
	}
}