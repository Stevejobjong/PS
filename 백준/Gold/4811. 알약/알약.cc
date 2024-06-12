#include<bits/stdc++.h>

using namespace std;
long long dp[100][100];
long long go(int whole, int half)
{
	if (whole == 0 && half == 0)
		return 1;
	if (dp[whole][half])
		return dp[whole][half];
	long long& ref = dp[whole][half];
	if (whole > 0)
		ref += go(whole - 1, half + 1);
	if (half > 0)
		ref += go(whole, half - 1);
	return ref;
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (true)
	{
		int num;
		cin >> num;
		if (num == 0)
			break;
		cout << go(num, 0) << '\n';
	}
	return 0;
}