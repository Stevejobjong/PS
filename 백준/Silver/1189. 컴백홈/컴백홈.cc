#include <bits/stdc++.h>
using namespace std;

int R, C, K;
pair<int, int> T;
char board[6][6];
int visited[6][6];
int ret = 0;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
void go(int r,int c, int distance)
{
	if (r == 0 && c == C - 1)
	{
		if (distance == K)
			ret++;
		return;
	}
	for (int l = 0; l < 4; l++)
	{
		int nr = r + dy[l];
		int nc = c + dx[l];
		if (nr < 0 || nc < 0 || nr >= R || nc >= C)
			continue;
		if (visited[nr][nc])
			continue;
		visited[nr][nc] = 1;
		go(nr, nc, distance + 1);
		visited[nr][nc] = 0;
	}
		
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			board[i][j] = str[j];
			if (str[j] == 'T')
				visited[i][j] = 1;
		}
	}
	if(R>=1)
		visited[R - 1][0] = 1;
	go(R - 1, 0, 1);
	cout << ret;

	return 0;
}