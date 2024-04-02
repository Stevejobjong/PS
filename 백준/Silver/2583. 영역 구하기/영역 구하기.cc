#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int M, N, K;
int depth;
void dfs(int i,int j) {
	visited[i][j] = 1;
	depth++;
	for (int k = 0; k < 4; k++) {
		int ni = i + dy[k];
		int nj = j + dx[k];
		if (0 <= ni && ni < M && 0 <= nj && nj < N && !visited[ni][nj]) {
			dfs(ni, nj);
		}
	}
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int cnt = 0;
	vector<int> v;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				visited[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				depth = 0;
				dfs(i, j);
				v.push_back(depth);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << ' ';
	}

	return 0;
}