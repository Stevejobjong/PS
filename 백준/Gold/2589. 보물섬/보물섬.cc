#include<bits/stdc++.h>
using namespace std;

char board[51][51];
int visited[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> v;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int H, W;
	cin >> H >> W;
	int ans = -1;

	for (int i = 0; i < H; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < W; j++)
		{
			board[i][j] = str[j];
			if (board[i][j] == 'L')
				v.push_back({ i,j });
		}
	}
	for (int idx = 0; idx < v.size(); idx++)
	{
		memset(visited, 0, sizeof(visited));
		queue<pair<int, int>> q;
		q.push(v[idx]);
		visited[v[idx].first][v[idx].second] = 1;
		int mx = 0;
		while (!q.empty())
		{
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++)
			{
				int ni = i + dy[k];
				int nj = j + dx[k];
				if (ni < 0 || ni >= H)
					continue;
				if (nj < 0 || nj >= W)
					continue;
				if (!visited[ni][nj] && board[ni][nj] == 'L')
				{
					mx = max(mx, visited[i][j]);
					visited[ni][nj] = visited[i][j] + 1;
					q.push({ ni,nj });
				}
			}
		}
		ans = max(ans, mx);
	}
	cout << ans;

	return 0;
}