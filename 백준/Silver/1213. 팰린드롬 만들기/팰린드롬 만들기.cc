#include <bits/stdc++.h>
using namespace std;

int cnt[200];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	string ans = "";
	char mid = NULL;
	int deathcnt = 2;
	cin >> str;
	int len = str.length();

	for (char c : str)
	{
		cnt[c]++;
	}
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (cnt[i] & 1)//홀수
		{
			deathcnt--;
			cnt[i]--;
			mid = i;
		}
		while (cnt[i] > 0)
		{
			ans = (char)i + ans + (char)i;
			cnt[i] -= 2;
		}
	}

	if (deathcnt <= 0)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	if(mid)
		ans.insert(ans.begin() + ans.length() / 2, mid);
	cout << ans;

	return 0;
}