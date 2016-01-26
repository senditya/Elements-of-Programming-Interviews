#include <iostream>

using namespace std;

string multiply(string x, string y)
{
	string result = "";
	int nx = x.length(), ny = y.length();

	for(int i=0; i<nx; i++)
		x[i] -= '0';
	for(int i=0; i<ny; i++)
		y[i] -= '0';

	for(int i=ny-1; i>=0; i--)
	{
		int carry = 0;

		for(int j=nx-1; j>=0; j--)
		{
			
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string x, y;
		cin >> x >> y;

		cout << x << " x " << y << endl;
		cout << "= " << multiply(x,y) << endl;
	}
}