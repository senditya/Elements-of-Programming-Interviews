#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int get_int(string &s)
{
	int n = s.length();
	int num = 0;

	for(int i=0; i<n; i++)
	{
		num = 10*num + (s[i] - '0');
	}

	return num;
}

int calc(string &s)
{
	stringstream ss(s);
	stack<int> pile;

	while(getline(ss, s, ','))
	{
		if(s[0] >= '0' && s[0] <= '9')
		{
			//element is number: convert to int and push into stack
			int num = get_int(s);
			//cout << s << ":" << num << endl;
			pile.push(num);
		}

		else
		{
			//element is operator: pop two elements from stack and push back result
			int num1 = pile.top();
			pile.pop();

			int num2 = pile.top();
			pile.pop();

			switch(s[0])
			{
				case '+':	pile.push(num2+num1);
							break;

				case '-':	pile.push(num2-num1);
							break;

				case '*':	pile.push(num2*num1);
							break;

				case '/':	pile.push(num2/num1);
							break;
			}
		}
	}

	return pile.top();
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		cout << s << endl << "= " << calc(s) << endl << endl;
	}
}