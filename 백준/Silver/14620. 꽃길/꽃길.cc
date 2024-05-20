#include <bits/stdc++.h>
using namespace std;

int board[20][20];
int visited[20][20];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
int ret = 987654321;
void go(int cnt, int sum)
{
	if (cnt == 3)
	{
		ret = min(ret, sum);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j])
				continue;
			int tmp = board[i][j];
			bool isOK = true;
			for (int k = 0; k < 4; k++)
			{
				int ni = i + dy[k];
				int nj = j + dx[k];

				if (ni < 0 || nj < 0 || ni >= N || nj >= N|| visited[ni][nj])
				{
					isOK = false;
					break;
				}
			}
			if (!isOK)
				continue;

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dy[k];
				int nj = j + dx[k];

				visited[ni][nj] = 1;
				tmp += board[ni][nj];
			}
			go(cnt + 1, sum + tmp);

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dy[k];
				int nj = j + dx[k];

				visited[ni][nj] = 0;
				tmp += board[ni][nj];
			}
		}
	}
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	go(0, 0);
	cout << ret;
	return 0;
}