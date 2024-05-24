#include <bits/stdc++.h>
using namespace std;

int N;
int population[11];
int visited[11];
int board[11];
vector<int> v[11];
pair<int, int> dfs(int here, int val)
{
	visited[here] = 1;
	pair<int, int> ret = { 1,population[here] };

	for (int there : v[here])
	{
		if (visited[there])
			continue;
		if (board[there] != val)
			continue;
		pair<int, int> tmp = dfs(there, val);
		ret.first += tmp.first;
		ret.second += tmp.second;
	}

	return ret;
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	int ret = 987654321;
	for (int i = 1; i <= N; i++)
	{
		cin >> population[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++)
		{
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}
	for (int i = 1; i < (1 << N) - 1; i++)
	{
		memset(visited, 0, sizeof(visited));
		memset(board, 0, sizeof(board));
		int a = -1;
		int b = -1;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				board[j + 1] = 1;
				a = j + 1;
			}
			else
				b = j + 1;
		}

		pair<int, int> c = dfs(a, 1);
		pair<int, int> d = dfs(b, 0);

		if (c.first + d.first == N)
			ret = min(ret, abs(c.second - d.second));
	}

	if (ret == 987654321)
		cout << -1;
	else
		cout << ret;

	return 0;
}