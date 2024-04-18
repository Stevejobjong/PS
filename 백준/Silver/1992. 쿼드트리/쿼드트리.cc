#include <bits/stdc++.h>
using namespace std;

int N;
char arr[65][65];

string quard(int i,int j,int size) {
	if (size == 1) {
		return string(1, arr[i][j]);
	}
	char origin = arr[i][j];
	for (int k = i; k < i + size; k++) {
		for (int l = j; l < j + size; l++) {
			if (origin != arr[k][l])
			{
				string ret = "(";
				ret += quard(i, j, size / 2);
				ret += quard(i, j + size / 2, size / 2);
				ret += quard(i + size / 2, j, size / 2);
				ret += quard(i + size / 2, j + size / 2, size / 2);
				ret += ")";
				return ret;
			}
		}
	}
	return string(1, arr[i][j]);
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < N; j++) {
			arr[i][j] = str[j];
		}
	}
	cout << quard(0, 0, N);

	return 0;
}