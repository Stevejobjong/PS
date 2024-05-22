#include <bits/stdc++.h>
using namespace std;

int W[17][17];
vector<int> v[16];
int N;
int a[4];
int ans = 987654321;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	map<int,vector<vector<int>>> ansV;
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int n;
			cin >> n;
			v[i].push_back(n);
		}
	}
	for (int i = 0; i < (1 << N); i++)
	{
		int b, c, d, e, cost;
		b = c = d = e = cost = 0;
		vector<int> ret;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				ret.push_back(j + 1);
				b += v[j][0];
				c += v[j][1];
				d += v[j][2];
				e += v[j][3];
				cost += v[j][4];
			}
		}
		if (b >= a[0] && c >= a[1] && d >= a[2] && e >= a[3])
		{
			if (ans >= cost)
			{
				ans = cost;
				ansV[ans].push_back(ret);
			}
		}
	}
	if (ans == 987654321)
		cout << -1;
	else
	{
		cout << ans << '\n';
		sort(ansV[ans].begin(), ansV[ans].end());
		for (int i : ansV[ans][0])
			cout << i << ' ';
	}

	return 0;
}