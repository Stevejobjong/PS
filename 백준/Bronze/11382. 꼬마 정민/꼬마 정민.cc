#include<bits/stdc++.h>

using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long a;
	long long ans = 0;
	long long t = 3;
	while (t--)
	{
		cin >> a;
		ans += a;
	}
	cout << ans;
	return 0;
}