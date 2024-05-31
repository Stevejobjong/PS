#include<bits/stdc++.h>

using namespace std;
int N;
int W[17][17];
int dp[17][1 << 17];
int go(int here, int visited)
{
	if (visited == (1 << N) - 1)
	{
		return W[here][0] != 0 ? W[here][0] : 987654321;
	}
	int& ret = dp[here][visited];
	if (ret != -1)
		return ret;
	ret = 987654321;

	for (int i = 0; i < N; i++)
	{
		if (visited & (1 << i))
			continue;
		if (W[here][i] == 0)
			continue;
		ret = min(ret, go(i, visited | (1 << i)) + W[here][i]);
	}
	return ret;
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 1);

	return 0;
}