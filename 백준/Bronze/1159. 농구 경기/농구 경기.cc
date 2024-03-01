#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	map<char, int> m;
	bool select = false;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		m[name[0]]++;
	}
	for (auto a : m) {
		if (a.second >= 5) {
			cout << a.first;
			select = true;
		}
	}
	if (!select)
		cout << "PREDAJA";

	return 0;
}
