#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int L;
	cin >> N >> L;
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		bool isOK = true;
		int visited[101] = { 0, };
		for (int j = 1; j < N; j++)
		{
			int num = board[i][j - 1] - board[i][j];
			if (abs(num) > 1)
			{
				isOK = false;
				break;
			}
			else if (num == 1)
			{
				int tmp = L - 1;
				int k = j;
				visited[k] = 1;
				while (tmp--)
				{
					k++;
					if (board[i][k] != board[i][j])
					{
						isOK = false;
						break;
					}
					visited[k] = 1;
				}
			}
			else if (num == -1)
			{
				int tmp = L - 1;
				int k = j - 1;
				if(visited[k])
				{
					isOK = false;
					break;
				}
				while (tmp--)
				{
					k--;
					if (k < 0 || board[i][k] != board[i][j - 1] || visited[k])
					{
						isOK = false;
						break;
					}
					visited[k] = 1;
				}
			}
		}
		if (isOK)
			ret++;
	}

	for (int i = 0; i < N; i++)
	{
		bool isOK = true;
		int visited[101] = { 0, };
		for (int j = 1; j < N; j++)
		{
			int num = board[j-1][i] - board[j][i];
			if (abs(num) > 1)
			{
				isOK = false;
				break;
			}
			else if (num == 1)
			{
				int tmp = L - 1;
				int k = j;
				visited[k] = 1;
				while (tmp--)
				{
					k++;
					if (board[k][i] != board[j][i])
					{
						isOK = false;
						break;
					}
					visited[k] = 1;
				}
			}
			else if (num == -1)
			{
				int tmp = L - 1;
				int k = j - 1;
				if (visited[k])
				{
					isOK = false;
					break;
				}
				while (tmp--)
				{
					k--;
					if (k < 0 || board[k][i] != board[j - 1][i] || visited[k])
					{
						isOK = false;
						break;
					}
					visited[k] = 1;
				}
			}
		}
		if (isOK)
			ret++;
	}

	cout << ret;
	return 0;
}