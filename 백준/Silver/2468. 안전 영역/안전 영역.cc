#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int N;
void dfs(int i, int j, int d) {
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int ni = dy[k] + i;
		int nj = dx[k] + j;
		if (0 <= ni && ni < N && 0 <= nj && nj<N && !visited[ni][nj] && board[ni][nj]>d) {
			dfs(ni, nj, d);
		}
	}
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int maxi=-1;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			maxi = max(n, maxi);
			board[i][j] = n;
		}
	}
	for (int d = 0; d <= maxi; d++) {
		int cnt = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && board[i][j] > d) {
					dfs(i, j, d);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;

	return 0;
}