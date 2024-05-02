#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int CheeseCount(int h, int w)
{
	int ret = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 1)
				ret++;
		}
	}
	return ret;
}
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
		}
	}
	while ((cnt=CheeseCount(H, W))!=0) 
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
				if (visited[ny][nx] || board[ny][nx] == 1)
					continue;
				q.push({ ny,nx });
				visited[ny][nx] = 1;
			}
		}

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (board[i][j] == 1)
				{
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (nx < 0 || nx >= W)
							continue;
						if (ny < 0 || ny >= H)
							continue;
						if (visited[ny][nx])
						{
							board[i][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
	cout << s.size() << '\n';
	cout<<s.top();
	return 0;
}