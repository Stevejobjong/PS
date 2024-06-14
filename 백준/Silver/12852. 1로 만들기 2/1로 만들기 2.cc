#include<bits/stdc++.h>

using namespace std;
int dp[1000001][2];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	vector<int> v;
	int cnt = 0;
	cin >> n;

	dp[1][0] = 0;
	dp[1][1] = -1;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + 1;
		dp[i][1] = i - 1;
		if (i % 3 == 0 && dp[i][0] > dp[i / 3][0] + 1)
		{
			dp[i][0] = dp[i / 3][0] + 1;
			dp[i][1] = i / 3;
		}
		if (i % 2 == 0 && dp[i][0] > dp[i / 2][0] + 1)
		{
			dp[i][0] = dp[i / 2][0] + 1;
			dp[i][1] = i / 2;
		}
	}
	v.push_back(n);
	while (dp[n][1] != -1)
	{
		cnt++;
		v.push_back(dp[n][1]);
		n = dp[n][1];
	}
	cout << cnt << '\n';
	for (int i : v)
		cout << i << ' ';

	return 0;
}