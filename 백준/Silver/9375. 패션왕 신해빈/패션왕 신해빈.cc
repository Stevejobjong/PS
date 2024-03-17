#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T = 0;
	cin >> T;
	while (T--) {
		int n = 0;
		int ans = 1;
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			string tmp;
			string type;
			cin >> tmp >> type;
			m[type]++;
		}
		for (auto a : m) {
			ans *= a.second + 1;
		}
		cout << --ans << '\n';
	}
}