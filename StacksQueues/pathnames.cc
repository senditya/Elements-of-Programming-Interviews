#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

bool shortcut(string &s)
{
	if(s.length() == 0 || s[0] == '.')
		return false;
	
	stringstream ss(s);
	string str;
	stack<string> stack;

	getline(ss, str, '/');
	stack.push(str);

	while(getline(ss, str, '/'))
	{
		if(str == "..")
		{
			if(stack.empty() || stack.top() == "..")
				stack.push(str);

			else if(stack.top() == "\0")
				continue;

			else
				stack.pop();
		}

		else if(str == "." || str == "\0")
			continue;

		else
			stack.push(str);
	}

	s = "";

	while(!stack.empty())
	{
		s = stack.top() + "/" + s;
		stack.pop();
	}

	return true;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		cout << s << endl;

		if(shortcut(s))
			cout << s << endl << endl;
		else
			cout << "INVALID PATHNAME" << endl;
	}
}