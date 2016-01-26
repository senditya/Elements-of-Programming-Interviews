#include <iostream>
#include <bitset>

using namespace std;

short parity(unsigned long long int x)
{
	int wordLen = 64;

	while(wordLen != 1)
	{
		wordLen /= 2;

		x ^= x >> wordLen;
	}

	return x & 0x1;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		unsigned long long int x;
		cin >> x;
		cout << bitset<64>(x) << endl;

		cout << "Parity = " << parity(x) << endl;
	}
}