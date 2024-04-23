#include <bits/stdc++.h>
using namespace std;

int num[10][10];
int ans = -1;
int CurNum = 0;
int N, M;
bool Check(int num) {
	int n = sqrt(num);
	return num == n * n;
}
void Recursive(int i, int j, int di, int dj) {
	CurNum *= 10;
	CurNum += num[i][j];
	if (Check(CurNum))
		ans = max(ans, CurNum);
	if (i + di < 0 || i + di >= N || j + dj < 0 || j + dj >= M)
		return;
	Recursive(i + di, j + dj, di, dj);
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			num[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int di = -N + 1; di < N; di++) {
				for (int dj = -M + 1; dj < M; dj++) {
					if (!di && !dj) {
						if(Check(num[di][dj]))
							ans = max(ans, num[di][dj]);
						continue;
					}
					CurNum = 0;
					Recursive(i, j, di, dj);
				}
			}
		}
	}
	cout << ans;
	return 0;
}