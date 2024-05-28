#include<bits/stdc++.h>

using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int ans = 0;
	int X;
	cin >> X;
	while (X & ((1 << 7) - 1))
	{
		if ((X & 1))
		{
			ans++;
		}
		X = X >> 1;
	}

	cout << ans;

	return 0;
}