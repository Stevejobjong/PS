#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int M;
	int tmp = 0;
	string str;
	map<int, string> ismap;
	map<string, int> simap;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		ismap[i] = str;
		simap[str] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (isdigit(str[0]))
		{
			cout << ismap[stoi(str)] << '\n';
		}
		else
		{
			cout << simap[str] << '\n';
		}
	}
}