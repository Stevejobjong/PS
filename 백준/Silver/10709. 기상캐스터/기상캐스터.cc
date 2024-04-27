#include <bits/stdc++.h>
using namespace std;

char board[101][101];
int visited[101][101];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int H, W;
	cin >> H;
	cin >> W;
	queue<pair<int, int>> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'c')
			{
				q.push({ i,j });
				visited[i][j] = 0;
			}
			else
				visited[i][j] = -1;
		}
	}
	while (q.size()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		if (j + 1 < W && visited[i][j+1] == -1)
		{
			visited[i][j + 1] = visited[i][j] + 1;
			q.push({ i,j + 1 });
		}

	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
