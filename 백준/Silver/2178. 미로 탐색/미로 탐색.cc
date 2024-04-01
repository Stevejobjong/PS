#include <bits/stdc++.h>
using namespace std;

int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int board[101][101];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = str[j] - '0';
		}
	}

	q.push({ 0,0 });
	visited[0][0] = 1;

	while (q.size()) {
		int CurY = q.front().first;
		int CurX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int NewY = CurY + dy[i];
			int NewX = CurX + dx[i];

			if (0 <= NewX && NewX <= 100 && 0 <= NewY && NewY <= 100 && board[NewY][NewX]&& !visited[NewY][NewX])
			{
				if (NewY == N - 1 && NewX == M - 1) {
					cout << visited[CurY][CurX]+1;
					return 0;
				}
				q.push({ NewY,NewX });
				visited[NewY][NewX] = visited[CurY][CurX] + 1;
			}
		}
	}
	return 0;
}