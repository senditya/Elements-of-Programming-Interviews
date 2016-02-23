#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct range
{
	int start;
	int end;
	bool left_open;
	bool right_open;
};

void print_ranges(vector<range> &intervals)
{
	int n = (int)intervals.size();

	for(int i=0; i<n; i++)
	{
		if(intervals[i].left_open)
			cout << "(";
		else
			cout << "[";

		cout << intervals[i].start << "," << intervals[i].end;

		if(intervals[i].right_open)
			cout << ") ";
		else
			cout << "] ";
	}

	cout << endl;
}

bool comp(range r1, range r2)
{
	return r1.start < r2.start;
}

range merge(range r1, range r2)
{
	range r;

	if(r1.start < r2.start)
	{
		r.start = r1.start;
		r.left_open = r1.left_open;
	}
	else if(r1.start > r2.start)
	{
		r.start = r2.start;
		r.left_open = r2.left_open;
	}
	else
	{
		r.start = r1.start;
		r.left_open = r1.left_open && r2.left_open;
	}

	if(r1.end > r2.end)
	{
		r.end = r1.end;
		r.right_open = r1.right_open;
	}
	else if(r1.end < r2.end)
	{
		r.end = r2.end;
		r.right_open = r2.right_open;
	}
	else
	{
		r.end = r1.end;
		r.right_open = r1.right_open && r2.right_open;
	}

	return r;
}

bool overlaps(range r1, range r2)
{
	if(r1.start < r2.start)
	{
		if(r1.end < r2.start)
			return false;
		else
			return true;
	}

	else
	{
		if(r2.end < r1.start)
			return false;
		else
			return true;
	}
}

vector<range> range_union(vector<range> &intervals)
{
	sort(intervals.begin(), intervals.end(), comp);

	vector<range> total_range;
	range current;

	int n = (int)intervals.size();

	current = intervals[0];
	for(int i=1; i<n; i++)
	{
		if(overlaps(current, intervals[i]))
		{
			//cout << "overlaps to current at " << i << endl;
			current = merge(current, intervals[i]);
		}

		else
		{
			//cout << "new current at " << i << endl;
			total_range.push_back(current);
			current = intervals[i];
		}
	}

	total_range.push_back(current);

	return total_range;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		range r;
		vector<range> intervals(n);
		for(int i=0; i<n; i++)
			cin >> intervals[i].start >> intervals[i].end >> intervals[i].left_open >> intervals[i].right_open;

		print_ranges(intervals);

		// sort(intervals.begin(), intervals.end(), comp);
		// print_ranges(intervals);

		vector<range> total_range = range_union(intervals);
		print_ranges(total_range);
		cout << endl;
	}
}