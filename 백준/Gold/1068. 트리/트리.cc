#include<bits/stdc++.h>
using namespace std;

vector<int> v[51];
int r, root;
int Dfs(int idx)
{
	int ret = 0;
	int ChildCnt = 0;
	for (int i = 0; i < v[idx].size(); i++) 
	{
		if (v[idx][i] == r)
			continue;
		ret += Dfs(v[idx][i]);
		ChildCnt++;
	}
	if (ChildCnt == 0)
		return 1;
	return ret;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == -1)
			root = i;
		else
			v[tmp].push_back(i);
	}
	cin >> r;
	if (r == root)
		cout << 0;
	else
		cout << Dfs(root);

	return 0;
}