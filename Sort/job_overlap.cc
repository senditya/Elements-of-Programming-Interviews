#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_overlap(vector<int> &starts, vector<int> &ends)
{
	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());

	int n = (int)starts.size();
	int num_active = 0;
	int max_active = 0;

	int end_ptr=0, start_ptr=0;

	while(end_ptr != n)
	{
		int end_time = ends[end_ptr];

		while(start_ptr < n && starts[start_ptr] < end_time)
		{
			start_ptr++;
			num_active++;
		}

		if(num_active > max_active)
			max_active = num_active;

		end_ptr++;
		num_active--;
	}

	return max_active;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<int> starts(n), ends(n);

		for(int i=0; i<n; i++)
			cin >> starts[i] >> ends[i];

		int max = max_overlap(starts, ends);
		cout << max << endl;
	}
}