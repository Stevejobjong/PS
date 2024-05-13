#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int cnt;
	vector<pair<int, int>> v;
	cin >> N;
	cin >> cnt;
	while (cnt--)
	{
		int num;
		cin >> num;
		if (v.size() == N)
		{
			bool isFind = false;
			int mn = 1001;
			for (int i = 0; i < v.size(); i++)
			{
				mn = min(mn, v[i].second);
				if (num == v[i].first)
				{
					v[i].second++;
					isFind = true;
				}
			}
			if (!isFind)
			{
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i].second == mn)
					{
						v.erase(v.begin() + i);
						break;
					}
				}
				v.push_back({ num,0 });
			}
		}
		else
		{
			bool isFind = false;
			for (int i = 0; i < v.size(); i++)
			{
				if (num == v[i].first)
				{
					v[i].second += 1;
					isFind = true;
				}
			}
			if (!isFind)
			{
				v.push_back({ num,0 });
			}

		}
	}
	sort(v.begin(), v.end());
	for (auto i : v)
		cout << i.first << ' ';
	
	return 0;
}