#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void print_array(int *array, int n)
{
	for(int i=0; i<n; i++)
		cout << array[i] << " ";
	cout << endl;
}

int longest_range(int *array, int n)
{
	int min = array[0], max = array[0];
	unordered_map<int, bool> hash;

	for(int i=0; i<n; i++)
	{
		hash[array[i]] = true;

		if(array[i] < min)
			min = array[i];
		if(array[i] > max)
			max = array[i];
	}

	int max_len = 1;
	int l = 1;
	int start = min+1;

	while(start <= max)
	{
		if(hash.find(start) != hash.end())
		{
			l++;
			start++;
		}

		else
		{
			if(l > max_len)
				max_len = l;

			while(start <= max)
			{
				start++;

				if(hash.find(start) != hash.end())
					break;
			}

			l = 1;
			start++;
		}
	}

	return max_len;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int array[n];
		for(int i=0; i<n; i++)
			cin >> array[i];

		int l = longest_range(array, n);

		print_array(array, n);
		cout << l << endl << endl;
	}
}