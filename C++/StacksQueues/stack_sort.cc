#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &stack, int x)
{
	if(stack.empty() || x >= stack.top())
		stack.push(x);

	else
	{	
		int y = stack.top();
		stack.pop();

		insert(stack, x);
		stack.push(y);
	}
}

void sort(stack<int> &stack)
{
	if(!stack.empty())
	{
		int x = stack.top();
		stack.pop();

		sort(stack);
		
		insert(stack, x);
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

		stack<int> stack;
		int x;
		for(int i=0; i<n; i++)
		{
			cin >> x;
			cout << x << " ";
			stack.push(x);
		}
		cout << endl;

		sort(stack);

		while(!stack.empty())
		{
			cout << stack.top() << " ";
			stack.pop();
		}

		cout << endl << endl;
	}
}