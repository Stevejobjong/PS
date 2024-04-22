#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	int l, r;
	int J;
	int ans = 0;
	cin >> N >> M >> J;
	l = 1;
	r = M;
	for (int i = 0; i < J; i++) {
		int num;
		int tmp = 0;
		cin >> num;
		if (num > r) {
			tmp = num - r;
			l += tmp;
			r += tmp;
			ans += tmp;
		}
		else if (num < l)
		{
			tmp = l - num;
			l -= tmp;
			r -= tmp;
			ans += tmp;
		}
	}
	cout << ans;

	return 0;
}