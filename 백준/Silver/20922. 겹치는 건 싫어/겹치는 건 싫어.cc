#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N = 0, K = 0;
	int ans = 0;
	int tmp = -1;
	int maxi = -1;
	map<int, queue<int>> m;
	vector<int> a;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < a.size(); i++)
	{
		m[a[i]].push(i);
		if (m[a[i]].size() > K)
		{
			int idx = m[a[i]].front();
			tmp = max(tmp, idx);
			m[a[i]].pop();

			maxi = max(ans, maxi);

			ans = i - tmp;
		}
		else
		{
			ans++;
		}
	}
	maxi = max(ans, maxi);
	cout << maxi;


	return 0;
}