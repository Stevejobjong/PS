#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int R, C;
char board[1001][1001];
int visited[1001][1001];
int fire[1001][1001];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> R >> C;
	pair<int, int> J;
	queue<pair<int, int>> q;
	fill(&fire[0][0], &fire[0][0] + 1001 * 1001, 987654321);
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = str[j];
			if (str[j] == 'J')
			{
				J.first = i;
				J.second = j;
			}
			else if (str[j] == 'F')
			{
				q.push({ i,j });
				fire[i][j] = 1;
			}

		}
	}
	while (q.size())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ni = dy[k] + i;
			int nj = dx[k] + j;
			if (ni < 0 || nj < 0 || ni >= R || nj >= C || board[ni][nj] == '#')
				continue;
			if (fire[ni][nj]== 987654321)
			{
				fire[ni][nj] = fire[i][j] + 1;
				q.push({ ni,nj });
			}
		}
	}

	q.push(J);
	visited[J.first][J.second] = 1;

	while (q.size())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ni = dy[k] + i;
			int nj = dx[k] + j;


			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
			{
				cout << visited[i][j];
				return 0;
			}

			if (visited[ni][nj])
				continue;

			if (fire[ni][nj] <= visited[i][j] + 1 || board[ni][nj] == '#')
				continue;


			visited[ni][nj] = visited[i][j] + 1;
			q.push({ ni,nj });
		}
	}
	cout << "IMPOSSIBLE ";

	return 0;
}