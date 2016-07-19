#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print_vector(vector< pair<int, int> > &busy)
{
	int n = (int)busy.size();

	for(int i=0; i<n; i++)
		cout << "(" << busy[i].first << "," << busy[i].second << ") ";
	cout << endl; 
}

// void interval_union(vector< pair<int, int> > &busy, pair<int,int> interval, vector< pair<int, int> > &new_busy)
// {
// 	int start, end;
// 	int i, n = (int)busy.size();

// 	for(i=0; i<n; i++)
// 	{
// 		if(busy[i].second > interval.first)
// 			break;
// 	}
// 	start = i;

// 	for(i=i; i<n; i++)
// 	{
// 		if(busy[i].first > interval.second)
// 			break;
// 	}
// 	end = i;

// 	if(end == 0)
// 	{
// 		//new interval at beginning
// 		new_busy.push_back(interval);
// 		new_busy.insert(new_busy.end(), busy.begin(), busy.end());
// 	}

// 	else if(start == n)
// 	{
// 		//new interval at end
// 		new_busy = busy;
// 		new_busy.push_back(interval);
// 	}

// 	else
// 	{
// 		//new interval somewhere in between
// 		int union_start, union_end;

// 		if(busy[start].first < interval.first)
// 			union_start = busy[start].first;
// 		else
// 			union_start = interval.first;

// 		if(busy[end-1].second > interval.second)
// 			union_end = busy[end-1].second;
// 		else
// 			union_end = interval.second;

// 		for(i=0; i<start; i++)
// 			new_busy.push_back(busy[i]);

// 		new_busy.push_back(make_pair(union_start, union_end));

// 		for(i=end; i<n; i++)
// 			new_busy.push_back(busy[i]);
// 	}
// }

bool is_before(pair<int,int> &interval1, pair<int,int> &interval2)
{
	if(interval1.second < interval2.first)
		return true;
	else
		return false;
}

bool overlap(pair<int,int> &interval1, pair<int,int> &interval2)
{
	if(interval1.first < interval2.first)
	{
		if(interval1.second < interval2.first)
			return false;
		else
			return true;
	}

	else
	{
		if(interval2.second < interval1.first)
			return false;
		else
			return true;
	}
}

pair<int,int> combine(pair<int,int> interval1, pair<int,int> interval2)
{
	pair<int,int> interval;

	if(interval1.first < interval2.first)
		interval.first = interval1.first;
	else
		interval.first = interval2.first;

	if(interval1.second > interval2.second)
		interval.second = interval1.second;
	else
		interval.second = interval2.second;

	return interval;
}

void interval_union(vector< pair<int, int> > &busy, pair<int,int> interval, vector< pair<int, int> > &new_busy)
{
	int n = (int)busy.size();
	int i=0;

	while(i<n)
	{
		if(!is_before(busy[i], interval))
			break;

		else
		{
			if(overlap(busy[i], interval))
				interval = combine(busy[i], interval);
			else
				new_busy.push_back(busy[i]);

			i++;
		}
	}

	while(i<n)
	{
		if(!overlap(busy[i], interval))
			break;
		else
			interval = combine(busy[i], interval);
		i++;
	}

	new_busy.push_back(interval);

	while(i<n)
	{
		new_busy.push_back(busy[i]);
		i++;
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

		vector< pair<int, int> > busy;
		int start, end;
		for(int i=0; i<n; i++)
		{
			cin >> start >> end;
			busy.push_back(make_pair(start,end));
		}

		pair<int,int> interval;
		cin >> start >> end;
		interval = make_pair(start, end);

		vector< pair<int,int> > new_busy;
		interval_union(busy, interval, new_busy);

		cout << "SCHEDULE: ";
		print_vector(busy);
		cout << "NEW INTERVAL: (" << interval.first << "," << interval.second << ")" << endl;
		cout << "NEW SCHEDULE: ";
		print_vector(new_busy);
		cout << endl;
	}
}