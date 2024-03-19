#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		stack<char> s;
		for (int i = 0; i < str.size(); i++)
		{
			if (!s.empty() && s.top() == str[i])
				s.pop();
			else
				s.push(str[i]);
		}
		if (s.empty())
			ans++;
	}

	cout << ans;

	return 0;
}