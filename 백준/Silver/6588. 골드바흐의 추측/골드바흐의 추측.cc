#include <bits/stdc++.h>
using namespace std;

int prime[1000001];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 2; i < sqrt(1000000); i++) {
		if (prime[i])
			continue;
		for (int j = 2; j * i <= 1000000; j++) {
			prime[j * i] = 1;
		}
	}
	while (1) {
		int n;
		cin >> n;
		if (!n)
			return 0;

		for (int i = 2; i <= n; i++) {
			if (!prime[i] && !prime[n - i])
			{
				cout << n << " = " << i << " + " << n - i;
				cout << '\n';
				break;
			}
		}
	}
	return 0;
}
