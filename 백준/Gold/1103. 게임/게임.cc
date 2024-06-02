#include<bits/stdc++.h>

using namespace std;
int N, M;
char board[51][51];
int visited[51][51];
int dp[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int go(int y, int x)
{
	if (0 > y || 0 > x || y >= N || x >= M || board[y][x] == 'H')
		return 0;
	if (visited[y][x]) {
		cout << -1 << "\n";
		exit(0);
	}

	if (dp[y][x])
		return dp[y][x];
    
	visited[y][x] = 1;
	int distance = board[y][x] - '0';
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * distance;
		int nx = x + dx[i] * distance;
		dp[y][x] = max(dp[y][x], go(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return dp[y][x];
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = str[j];
		}
	}
	cout << go(0, 0);

	return 0;
}