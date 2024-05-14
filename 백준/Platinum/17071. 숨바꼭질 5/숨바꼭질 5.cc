#include <bits/stdc++.h>
using namespace std;

int visited[2][500001];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	if (N == K)
	{
		cout << 0;
		return 0;
	}
	bool isFind = false;
	queue<int> q;
	visited[0][N] = 1;
	q.push(N);
	int turn = 1;
	while (int qSize = q.size())
	{
		K += turn;
		if (K > 500000)
			break;
		if (visited[turn % 2][K])
		{
			isFind = true;
			break;
		}
		for (int i = 0; i < qSize; i++)
		{
			int x = q.front();
			q.pop();
			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx>500000)
					continue;
				if (!visited[turn % 2][nx])
				{
					visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
					if (nx == K)
					{
						isFind = true;
						break;
					}
					q.push(nx);
				}
			}
			if (isFind) break;
		}
		if (isFind) break;

		turn++;
	}
	if (isFind)
		cout << turn;
	else
		cout << -1;

	return 0;
}