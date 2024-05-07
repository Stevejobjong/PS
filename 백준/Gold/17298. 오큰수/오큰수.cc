#include<bits/stdc++.h>
using namespace std;

int num[1000001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> s;
	stack<int> s2;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (s.empty())
		{
			s.push(num[i]);
			s2.push(-1);
		}
		else
		{
			while (!s.empty() && s.top() <= num[i])
				s.pop();
			if (s.empty())
				s2.push(-1);
			else			
				s2.push(s.top());
			
			s.push(num[i]);
		}
	}
	while (!s2.empty())
	{
		cout << s2.top() << ' ';
		s2.pop();
	}

	return 0;
}