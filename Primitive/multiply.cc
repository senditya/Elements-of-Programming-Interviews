#include <iostream>
#include <bitset>

using namespace std;

unsigned add(unsigned a, unsigned b)
{
	//cout << "Adding: " << bitset<8>(a) << " " << bitset<8>(b) << endl;

	unsigned c_in = 0U;
	unsigned sum = 0U;

	unsigned temp_a = a, temp_b = b;
	unsigned k = 1U;

	while(temp_a || temp_b)
	{
		temp_a >>= 1;
		temp_b >>= 1;

		unsigned a_k = a&k, b_k = b&k;
		k <<= 1;

		unsigned s = a_k ^ b_k ^ c_in;
		c_in = (a_k & b_k) | (c_in & (a_k ^ b_k));
		c_in <<= 1;

		sum = sum | s;
	}

	return sum;
}

unsigned multiply(unsigned x, unsigned y)
{
	unsigned product = 0;

	while(y != 0)
	{
		unsigned lsb = y & 1U;

		if(lsb == 1)
			product = add(product, x);

		y = y >> 1;
		x = x << 1;
	}

	return product;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		unsigned x, y;
		cin >> x >> y;

		cout << multiply(x, y) << endl;
	}
}