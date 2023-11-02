#include <bits/stdc++.h>

using namespace std;

int num[10];
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int number = 0;
	cin >> N;
	int ans = -1;
	while (N) {
		num[N % 10]++;
		N /= 10;
	}
	int tmp = num[9] + num[6];
	int tmp2 = tmp / 2 + tmp % 2;
	num[6] = tmp2;
	num[9] = tmp2;

	for (int i = 0; i < 10; i++) {
		if (ans < num[i]) {
			ans = num[i];
			number = i;
		}
	}

	cout << ans;

	return 0;
}

