#include <iostream>

using namespace std;

int sqrt(int n)
{
	int low = 0;
	int high = n;

	while(low < high)
	{
		int mid = low + (high-low)/2;

		//cout << low << " " << mid << " " << high << endl;

		if(mid * mid == n)
			return mid;

		else if(mid * mid > n)
			high = mid-1;

		else
		{
			low = mid+1;

			if(low * low > n)
				return mid;
		}	
	}

	return low;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int root_n = sqrt(n);
		cout << "SQUARE ROOT OF " << n << " = " << root_n << endl;
	}
}