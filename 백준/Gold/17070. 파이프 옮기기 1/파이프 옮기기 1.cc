#include<bits/stdc++.h>

using namespace std;
int N;
int board[20][20];
int dp[20][20][3];
bool CanMove(int y, int x, int type)
{
	//가로이동or세로이동 벽체크
	if (type == 0 || type == 2)
	{
		if (!board[y][x]) return true;
	}
	//대각 이동 벽체크
	else
	{
		if (!board[y][x] && !board[y - 1][x] && !board[y][x - 1]) return true;
	}
	return false;
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	dp[1][2][0] = 1;

	// 0 : 가로, 1 : 대각선, 2 : 세로
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			//가로,대각 이동 from 가로
			if (CanMove(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][0];
			if (CanMove(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][0];

			//세로,대각 이동 from 세로
			if (CanMove(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][2];
			if (CanMove(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][2];

			//가로,대각,세로 이동 from 대각
			if (CanMove(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][1];
			if (CanMove(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][1];
			if (CanMove(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];

	return 0;
}