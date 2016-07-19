#include <iostream>
#include <vector>

using namespace std;

void allPrimes(int n, vector<int> &primes)
{
	bool numbers[n];
	memset(numbers, 1, n);

	numbers[0] = 0;

	for(int i=1; i<n; i++)
	{
		int number = i+1;

		for(int j = number*number; j <= n; j += number)
			numbers[j-1] = 0;
	}

	for(int i=0; i<n; i++)
	{
		if(numbers[i] == 1)
			primes.push_back(i+1);
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<int> primes;
		allPrimes(n, primes);

		cout << "Prime numbers:" << endl;
		for(int i=0; i<(int)primes.size(); i++)
			cout << primes[i] << " ";
		cout << endl << endl;
	}
}