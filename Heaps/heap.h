#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define LEFT(ix) 2*ix+1
#define RIGHT(ix) 2*ix+2
#define PARENT(ix) ix/2

template<typename T>
class Heap
{
private:
		int heap_size;
		vector<T> *number;
		bool max;

public:
		Heap()
		{
			heap_size = 0;
			number = NULL;
		}

		void heapify(int ix)
		{
			int l_ix = LEFT(ix);
			int r_ix = RIGHT(ix);
			int extreme_ix = ix;

			if(max)
			{
				if(l_ix < heap_size && (*number)[l_ix] > (*number)[extreme_ix])
					extreme_ix = l_ix;
				if(r_ix < heap_size && (*number)[r_ix] > (*number)[extreme_ix])
					extreme_ix = r_ix;
			}

			else
			{
				if(l_ix < heap_size && (*number)[l_ix] < (*number)[extreme_ix])
					extreme_ix = l_ix;
				if(r_ix < heap_size && (*number)[r_ix] < (*number)[extreme_ix])
					extreme_ix = r_ix;
			}

			if(extreme_ix != ix)
			{	
				swap((*number)[extreme_ix], (*number)[ix]);
				heapify(extreme_ix);
			}
		}

		void build_heap(vector<T> *array, bool max=true)
		{
			heap_size = (int)array->size();
			this->max = max;
			number = array;

			for(int ix=heap_size/2-1; ix>=0; ix--)
				heapify(ix);
		}

		void heap_sort(vector<T> *array, bool reverse=false)
		{
			build_heap(array, !reverse);

			while(heap_size != 1)
			{
				swap((*number)[0], (*number)[heap_size-1]);
				heap_size--;
				heapify(0);
			}
		}

		T most_prior()
		{
			return (*number)[0];
		}

		void pop()
		{
			number->erase(number->begin());
			heap_size--;
			heapify(0);
		}

		void push(T x)
		{
			number->push_back(x);
			heap_size++;

			int ix = heap_size-1;
			while(ix != 0)
			{
				int p_ix = PARENT(ix);

				if(((*number)[ix] < (*number)[p_ix] && max) || ((*number)[ix] > (*number)[p_ix] && !max))
					break;

				swap((*number)[ix], (*number)[p_ix]);
				ix = p_ix;
			}
		}

		int size()
		{
			return heap_size;
		}
};