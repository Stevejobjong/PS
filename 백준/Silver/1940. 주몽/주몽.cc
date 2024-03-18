#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	map<int, int> m;
	int ans = 0;
	int N;
	int M;
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num == M / 2 && !(M & 1))
			continue;

		m[num]++;
		if (m[M - num])
			ans++;
	}
	cout << ans;
	return 0;
}