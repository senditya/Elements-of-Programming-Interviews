#include <iostream>
#include <climits>

using namespace std;

void print_array(int *array, int n)
{
	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

void firstProfit(int *prices, int n, int *profit)
{
	int minBuy = prices[0];

	for(int i=1; i<n; i++)
	{
		profit[i] = prices[i] - minBuy;

		if(prices[i] < minBuy)
			minBuy = prices[i];
	}
}

int maxProfit(int *prices, int n)
{
	int first_profit[n];
	first_profit[0] = INT_MIN;

	firstProfit(prices, n, first_profit);
	//print_array(first_profit, n);

	int max = INT_MIN;
	int max_profit1_ix = 1, max_profit1 = first_profit[1];
	int min_buy2_ix = 2;

	for(int i=3; i<n; i++)
	{
		if(prices[i]-prices[min_buy2_ix]+max_profit1 > max)
		{
			max = prices[i]-prices[min_buy2_ix]+max_profit1;
		}

		max_profit1_ix++;
		if(first_profit[max_profit1_ix] > max_profit1)
		{
			max_profit1 = first_profit[max_profit1_ix];
			min_buy2_ix = max_profit1_ix + 1;
		}
	}

	return max;
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

		int profit = maxProfit(prices, n);

		cout << "Max profit = " << profit << endl;
	}
}