#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int num[1001];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	int ans = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		dp[i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[j] + 1,dp[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans;

	return 0;
}