#include <iostream>

using namespace std;

unsigned divide(unsigned D, unsigned d)
{
	unsigned org_d = d;
	unsigned q = 0;

	while(d <= D)
		d <<= 1;

	d >>= 1;

	cout << bitset<8>(D) << " " << bitset<8>(d) << " " << bitset<8>(q) << endl;

	while(D >= org_d)
	{
		q <<= 1;
		q = q | 1U;

		D -= d;
		d >>= 1;

		while(d > D && d != 1U)
		{
			q <<= 1;
			d >>= 1;
		}

		cout << bitset<8>(D) << " " << bitset<8>(d) << " " << bitset<8>(q) << endl;
	}

	return q;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		unsigned x, y;
		cin >> x >> y;

		cout << divide(x, y) << endl;
	}
}