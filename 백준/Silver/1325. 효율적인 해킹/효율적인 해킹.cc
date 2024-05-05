#include<bits/stdc++.h>
using namespace std;

map<int, vector<int>> m;
vector<int> v[10001];
map<int, int> m2;
int visited[10001];
int N, M;
int Dfs(int idx)
{
	visited[idx] = 1;
	int ret = 1;
	//for (auto i : m[idx])
	//{
	//	if (!visited[i])
	//	{
	//		ret += Dfs(i);
	//	}
	//}
	for (auto i : v[idx])
	{
		if (!visited[i])
		{
			ret += Dfs(i);
		}
	}

	return ret;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int mx = -1;
	cin >> N >> M;
	for (int i = 0; i < M; i++) 
	{
		int n1, n2;
		cin >> n1 >> n2;
		//m[n2].push_back(n1);
		v[n2].push_back(n1);
	}
	for (int i = 1; i <= N; i++) 
	{
		memset(visited, 0, sizeof(visited));
		m2[i] = Dfs(i);
		mx = max(mx, m2[i]);
	}

	for (auto i : m2)
	{
		if (i.second == mx)
			cout << i.first << ' ';
	}

	return 0;
}