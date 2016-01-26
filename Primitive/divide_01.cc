#include <iostream>

using namespace std;

int divide(int x, int y)
{
	if(x < y)
		return 0;

	return divide(x-y, y) + 1;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int x, y;
		cin >> x >> y;

		cout << divide(x,y) << endl;
	}

	return 0;
}