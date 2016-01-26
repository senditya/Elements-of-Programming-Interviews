#include <iostream>
#include <climits>

using namespace std;

void maxProfit(int *prices, int n, int *profit)
{
	int minBuy = prices[0], min_day = 0;
	int max = INT_MIN, max_day, min_max_day;

	for(int i=1; i<n; i++)
	{
		if(prices[i] - minBuy > max)
		{
			max = prices[i] - minBuy;
			max_day = i;
			min_max_day = min_day;
		}

		if(prices[i] < minBuy)
		{
			minBuy = prices[i];
			min_day = i;
		}
	}

	profit[0] = max;
	profit[1] = min_max_day;
	profit[2] = max_day;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int prices[n];

		for(int i=0; i<n; i++)
			cin >> prices[i];

		int profit[3];
		maxProfit(prices, n, profit);

		cout << "Max profit = " << profit[0] << endl;
		cout << "Buy on day " << profit[1] << " ; Sell on day " << profit[2] << endl << endl;
	}
}