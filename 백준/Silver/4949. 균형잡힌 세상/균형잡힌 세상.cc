#include<bits/stdc++.h>
using namespace std;

int main(void) 
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	while (true)
	{
		getline(cin, str);
		if (str == ".")
			break;
		stack<char> s;
		bool isBalance = true;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				s.push('(');
			else if (str[i] == '[')
				s.push('[');
			else if (str[i] == ')')
			{
				if (s.empty()||s.top() != '(')
				{
					isBalance = false;
					break;
				}
				else
					s.pop();
			}
			else if (str[i] == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					isBalance = false;
					break;
				}
				else
					s.pop();
			}
		}
		if (isBalance && s.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}