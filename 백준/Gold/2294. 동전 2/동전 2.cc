#include<bits/stdc++.h>

using namespace std;
int dp[10001];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int tmp;
	fill(dp, dp + 10001, 987654321);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = tmp; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - tmp] + 1);
		}
	}
	if (dp[k] == 987654321)
		cout << -1;
	else
		cout << dp[k];
	return 0;
}