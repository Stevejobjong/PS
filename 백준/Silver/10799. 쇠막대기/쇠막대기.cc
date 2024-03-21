#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int cnt = 0;
	string str;
	stack<int> s;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(1);
		}
		else // ')'
		{
			s.pop();
			if (str[i - 1] != '(')
				cnt++;
			else if(!s.empty())
			{
				cnt += s.size();
			}
		}
	}
	cout << cnt;

	return 0;
}