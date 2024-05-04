#include<bits/stdc++.h>
using namespace std;

int board[10][10];
int visited[10][10];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> virus;
int N, M;
int Bfs() 
{
	int cnt = 0;
	queue<pair<int, int>> q(virus);
	fill(visited[0], visited[0] + 10 * 10, 0);
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= M || nx < 0)
				continue;
			if (ny >= N || ny < 0)
				continue;
			if (!visited[ny][nx] && board[ny][nx] == 0)
			{
				q.push({ ny,nx });
				visited[ny][nx] = 1;
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0&&!visited[i][j])
				cnt++;
		}
	}
	return cnt;
}
int Building(int cnt) 
{
	int ret = -1;
	if (cnt == 3)
	{
		return Bfs();
	}

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			if (board[i][j] == 0)
			{
				board[i][j] = 1;
				ret = max(ret, Building(cnt + 1));
				board[i][j] = 0;
			}
		}
	}
	return ret;
}
int main(void) 
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push({ i,j });

		}
	}
	cout << Building(0);

	return 0;
}