#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int visited[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			if (num == 2) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
			board[i][j] = num;
		}
	}

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= nx && nx < m && 0 <= ny && ny < n && !visited[ny][nx] && board[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (visited[i][j] == 0)
			{
				if (board[i][j] == 0) {
					cout << 0 << ' ';
				}
				else
				{
					cout << -1 << ' ';
				}
			}
			else
				cout << visited[i][j] - 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}