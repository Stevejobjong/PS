#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, C;
	unordered_map<int, int> m;
	unordered_map<int, int> mOrder;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (m[num]==0)
			mOrder[num] = i;
		m[num]++;
	}
	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [&](pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second)
			return mOrder[a.first] < mOrder[b.first];
		if (a.second > b.second)
			return true;
		else
			return false;
		});

	for (auto i : v) {
		for (int j = 0; j < i.second; j++) {
			cout << i.first << ' ';
		}
	}

	return 0;
}
