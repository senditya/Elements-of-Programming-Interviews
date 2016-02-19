#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T binary_search(vector<T> &array, T key)
{
	int low=0, high=(int)array.size()-1;

	while(low <= high)
	{
		int mid = low + (high-low)/2;

		if(array[mid] > key)
			high = mid-1;

		else if(array[mid] == key)
			return mid;

		else
			low = mid+1;
	}

	return -1;
}