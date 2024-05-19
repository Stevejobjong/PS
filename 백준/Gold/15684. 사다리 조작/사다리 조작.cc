#include <bits/stdc++.h>
using namespace std;

int N, M;
int H;
int line[14][34];
int ret = 10;
bool Check()
{
	for (int w = 1; w < N; w++)
	{
		int result = w;
		for (int h = 1; h <= H; h++)
		{
			if (line[result][h])
				result += 1;
			else if (result > 1 && line[result - 1][h])
				result -= 1;
		}
		if (result != w)
		{
			return false;
		}
	}
	return true;
}
void go(int i,int cnt)
{
	if (cnt > 3)
		return;
	if (Check())
	{
		ret = min(ret, cnt);
		return;
	}

	for (int w = 1; w < N; w++)
	{
		for (int h = i; h <= H; h++)
		{
			if (!line[w][h])
			{
				if (line[w - 1][h] || line[w + 1][h])
					continue;
				line[w][h] = 1;
				go(h,cnt + 1);
				line[w][h] = 0;
			}
		}
	}
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	cin >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		line[b][a] = 1;
	}
	go(1,0);
	if (ret > 3)
		cout << -1;
	else
		cout << ret;
	return 0;
}