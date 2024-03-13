#include <bits/stdc++.h>
using namespace std;

int psum[100001];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K;
	int tmp = 0;
	int ans = -10000000;
	vector<int> v;
	cin >> N;
	cin >> K;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		psum[i] = psum[i - 1] + tmp;
	}
	for (int i = K; i <= N; i++) {
		tmp = psum[i] - psum[i - K];
		ans = max(ans, tmp);
	}
	cout << ans;
}