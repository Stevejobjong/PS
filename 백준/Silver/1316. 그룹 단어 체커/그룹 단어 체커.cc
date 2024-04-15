#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int ans = 0;
	cin >> N;

	while (N--) {
		string str;
		int alpha[26] = { 0, };
		bool isGroup = true;
		cin >> str;
		stack<char> s;
		for (int i = 0; i < str.size(); i++) {
			if (!s.empty()) {
				if(s.top() != str[i])
					s.push(str[i]);
			}
			else {
				s.push(str[i]);
			}
		}
		while (!s.empty()) {
			if (alpha[s.top() - 'a'] == 1)
			{
				isGroup = false;
				break;
			}
			alpha[s.top() - 'a'] = 1;
			s.pop();
		}
		if (isGroup)
			ans++;
	}
	cout << ans;
	return 0;
}