#include <bits/stdc++.h>
using namespace std;
int N;
int board[23];
int ret = 987654321;
void go(int here)
{
	if (here == N)
	{
		int sum = 0;
			for (int j = 0; j < N; j++)
			{
				int cnt = 0;
				for (int i = 0; i < N; i++)
				{
					if (board[i] & (1 << j))
						cnt++;
				}
				sum += min(cnt, N - cnt);
			}
		ret = min(sum, ret);
		return;
	}

	go(here + 1);
	board[here] = ~board[here];
	go(here + 1);
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		int val = 1;
		for (int j = 0; j < N; j++)
		{
			if (str[j] == 'T')
			{
				board[i] |= val;
			}
			val *= 2;
		}
	}
	go(0);
	cout << ret;

	return 0;
}