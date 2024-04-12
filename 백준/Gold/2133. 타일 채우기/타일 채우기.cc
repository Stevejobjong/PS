#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int dp[30];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	if (N % 2 != 0) {
		cout << 0;
		return 0;
	}
	dp[0] = 1;
	for (int i = 2; i <= N; i += 2) {
		dp[i] += dp[i - 2] * 3;

		for (int j = 4; j <= i; j += 2)
		{
			dp[i] += dp[i - j] * 2;
		}

	}
	cout << dp[N];
	return 0;
}