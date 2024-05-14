#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[301][301];
int visited[301][301];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int x1, y1, x2, y2;
	bool isFind = false;
	int ret = 0;
	cin >> N >> M;
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = str[j];
		}
	}
	queue<pair<int, int>> q;
	q.push({ x1 - 1,y1 - 1 });
	visited[x1 - 1][y1 - 1] = 1;
	while (!isFind)
	{
		ret++;
		queue < pair<int, int>> tmp;
		while (q.size())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M)
					continue;
				if (visited[ny][nx])
					continue;
				visited[ny][nx] = visited[ny][nx] + 1;
				if (board[ny][nx] == '#')
				{
					isFind = true;
					break;
				}
				if (board[ny][nx] == '1')
					tmp.push({ ny,nx });
				else					
					q.push({ ny,nx });
			}
		}
		q = tmp;
	}
	cout << ret;
	return 0;
}