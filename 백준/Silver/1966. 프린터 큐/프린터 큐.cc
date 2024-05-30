#include<bits/stdc++.h>

using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;

	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<pair<int, bool>> v;
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			if (i == M)
				v.push_back({ num,true });
			else
				v.push_back({ num,false });
		}
		int cnt = 0;
		while (v.size())
		{
			int val = v[0].first;
			bool isErase = false;
			for (auto a : v)
			{
				if (val < a.first)
				{
					v.push_back(v[0]);
					v.erase(v.begin());
					isErase = true;
					break;
				}
			}
			if (!isErase)
			{
				cnt++;
				if (v[0].second)
				{
					cout << cnt << '\n';
					break;
				}
				v.erase(v.begin());
			}
		}

	}
	return 0;
}