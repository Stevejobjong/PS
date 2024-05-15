#include<bits/stdc++.h>
using namespace std;

char board[1501][1501];
int visited[2][1501][1501];
int Dvisited[1501][1501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int R, C;
	bool isFind = false;
	int ret = 0;
	cin >> R >> C;
	vector<pair<int, int>> v;
	queue<pair<int, int>> dotq;
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			board[i][j] = str[j];
			if (str[j] == 'L')
			{
				v.push_back({ i,j });
				dotq.push({ i,j });
			}
			if (str[j] == '.')
				dotq.push({ i,j });

		}
	}
	queue<pair<int, int>> q[2];

	for (int i=0;i<2;i++)
	{
		q[i].push(v[i]);
		visited[i][v[i].first][v[i].second] = 1;
	}
	while (!isFind)
	{
		ret++;
		for (int i = 0; i < 2; i++)
		{
			queue<pair<int, int>> tmp;
			while (q[i].size())
			{
				int y = q[i].front().first;
				int x = q[i].front().second;
				q[i].pop();
				for (int j = 0; j < 4; j++)
				{
					int ny = dy[j] + y;
					int nx = dx[j] + x;

					if (ny < 0 || nx < 0 || ny >= R || nx >= C)
						continue;
					if (visited[i][ny][nx])
						continue;
					visited[i][ny][nx] = visited[i][y][x] + 1;
					if (board[ny][nx] == 'L')
					{
						cout << ret - (1 - i);
						return 0;
					}
					if (board[ny][nx] == '.')
						q[i].push({ ny,nx });
					else if(board[ny][nx] == 'X')
						tmp.push({ ny,nx });
				}
			}
			q[i] = tmp;
		}
		queue<pair<int, int>> tmp;
		while (dotq.size())
		{
			int y = dotq.front().first;
			int x = dotq.front().second;
			dotq.pop();
			for (int j = 0; j < 4; j++)
			{
				int ny = dy[j] + y;
				int nx = dx[j] + x;

				if (ny < 0 || nx < 0 || ny >= R || nx >= C)
					continue;
				if (Dvisited[ny][nx])
					continue;
				Dvisited[ny][nx] = Dvisited[y][x] + 1;
				if (board[ny][nx] == 'X')
				{
					tmp.push({ ny,nx });
					board[ny][nx] = '.';
				}
				else
					dotq.push({ ny,nx });
			}
		}
		dotq = tmp;

	}

	return 0;
}