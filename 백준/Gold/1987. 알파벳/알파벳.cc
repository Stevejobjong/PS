#include<bits/stdc++.h>
using namespace std;

char board[21][21];
int visited[21][21];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int R, C;
int ret = -1;
void Dfs(int y, int x,vector<int>& v)
{
	ret = max((int)v.size(), ret);

	for (int i = 0; i < 4; i++)
	{
		bool isDuplicate = false;
		int ny = y + dy[i];
		int nx = x + dx[i];
		int n = board[ny][nx] - 'A';
		if (ny < 0 || nx < 0 || ny >= R || nx >= C)
			continue;
		if (visited[ny][nx])
			continue;
		for (int j : v)
		{
			if (n == j)
			{
				isDuplicate = true;
				break;
			}
		}
		if (isDuplicate)
			continue;
		visited[ny][nx] = 1;
		v.push_back(n);
		Dfs(ny, nx, v);
		v.pop_back();
		visited[ny][nx] = 0;
	}
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		cin >> board[i];
	}
	vector<int> v;
	v.push_back(board[0][0] - 'A');
	visited[0][0] = 1;
	Dfs(0, 0, v);
	cout << ret;

	return 0;
}