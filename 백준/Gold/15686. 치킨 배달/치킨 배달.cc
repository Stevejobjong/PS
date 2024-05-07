#include<bits/stdc++.h>
using namespace std;

int visited[51][51];
int board[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int N, M;
int ans;
int Func(int start,int cnt)
{
	int ret = 0;
	if (cnt == M)
	{
		for (auto i : home)
		{
			int dis = 1000000000;
			for (auto j : chicken)
			{
				if(visited[j.first][j.second])
					dis = min(dis, abs(i.first - j.first) + abs(i.second - j.second));
			}
			ret += dis;
		}
		return ret;
	}
	ret = 1000000000;
	for (int i = start; i < chicken.size(); i++)
	{
		int first = chicken[i].first;
		int second = chicken[i].second;
		if (!visited[first][second])
		{
			visited[first][second] = true;
			ret = min(Func(i+1,cnt + 1), ret);
			visited[first][second] = false;
		}
	}
	return ret;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				home.push_back({ i,j });
			else if (board[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	cout << Func(0, 0);
	return 0;
}