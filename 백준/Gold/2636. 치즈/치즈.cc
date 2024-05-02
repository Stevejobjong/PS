#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int H, W;
	int cnt = 0;
	stack<int> s;
	cin >> H >> W;
	for (int i = 0; i < H; i++) 
	{
		for (int j = 0; j < W; j++) 
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				cnt++;
		}
	}
	while (cnt) 
	{
		s.push(cnt);
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				visited[i][j] = 0;
			}
		}
		visited[0][0] = 1;
		while (q.size())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (nx < 0 || nx >= W)
					continue;
				if (ny < 0 || ny >= H)
					continue;
				if (visited[ny][nx])
					continue;
				if (board[ny][nx] == 1)
				{
					board[ny][nx] = 0;
					cnt--;
				}
				else
					q.push({ ny,nx });

				visited[ny][nx] = 1;
			}
		}
	}
	cout << s.size() << '\n';
	cout<<s.top();
	return 0;
}