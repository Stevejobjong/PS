#include<bits/stdc++.h>

using namespace std;
int T, W;
int dp[1001][31][2];
int board[1001];

int go(int t, int move, int tree)
{
	if (move < 0) return -INT_MAX;
	if (t == T) return 0;
	int& ret = dp[t][move][tree];
	if (ret != -1) return ret;

	return ret = max(go(t + 1, move - 1, tree ^ 1), go(t + 1, move, tree)) + (board[t] - 1 == tree);
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T >> W;
	memset(dp, -1, sizeof(dp));
	
	for (int i = 0; i < T; i++)
		cin >> board[i];

	cout << max(go(0, W - 1, 1), go(0, W, 0));

	return 0;
}