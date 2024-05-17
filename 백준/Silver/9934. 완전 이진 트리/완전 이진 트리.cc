#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int visited[1100];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int K;
	cin >> K;
	int cnt = pow(2, K) - 1;
	stack<vector<int>> s;
	for (int i = 0; i < cnt; i++)
	{
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 1; i < cnt; i *= 2)
	{
		vector<int> tmp;
		int num = i - 1;
		while (num < cnt)
		{
			tmp.push_back(v[num]);
			num += 2 * i;
		}
		s.push(tmp);
	}
	while (s.size())
	{
		for (int a : s.top())
			cout << a << ' ';
		s.pop();
		cout << '\n';
	}

	return 0;
}