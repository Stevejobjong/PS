#include <bits/stdc++.h>
using namespace std;

int visited[51][51];
int m[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int M;
int N;
void dfs(int x,int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx <= M && ny >= 0 && ny <= N && !visited[nx][ny] && m[nx][ny])
		{
			dfs(nx, ny);
		}
	}
	return;
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		fill(&m[0][0], &m[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		int cnt = 0;
		int K;
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			m[n1][n2] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[j][i] && m[j][i]) {
					dfs(j, i);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}
