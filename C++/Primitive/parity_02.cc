#include <iostream>
#include <bitset>

#define word_size 16
#define array_size 65536

short lookup[array_size];

using namespace std;


void calcParity(unsigned x)
{
	int ones = 0;
	int y = x;

	while(x != 0)
	{
		x &= (x-1);
		ones++;
	}

	lookup[y] = ones%2;
}

int getParity(unsigned long long int x)
{
	unsigned x_parts[4];
	unsigned long long int mask = array_size - 1;

	int ones = 0;

	for(int i=0; i<4; i++)
	{
		//cout << "mask : " <<  bitset<64>(mask) << endl;

		x_parts[i] = (unsigned)((x & mask) >> (i*16));
		mask = mask << 16;

		//cout << "part : " << bitset<16>(x_parts[i]) << endl << endl;

		if(lookup[x_parts[i]] == -1)
			calcParity(x_parts[i]);

		ones += lookup[x_parts[i]];
	}

	return ones%2;
}


int main()
{
	for(int i=0; i<array_size; i++)
		lookup[i] = -1;

	int t;
	cin >> t;

	while(t--)
	{
		unsigned long long int x;
		cin >> x;

		//cout << bitset<64>(x) << endl;
		cout << getParity(x) << endl;
	}
}