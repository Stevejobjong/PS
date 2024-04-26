#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<string> v;
	string num = "";

	while (N--) {
		string str;
		cin >> str;
		num = "";
		for (char c : str) {
			if (c >= '0' && c <= '9') {
				if (num == "")
					num = c;
				else
				{
					num += c;
				}
			}
			else {
				if (num != "")
				{
					while (num[0] == '0' && num.size() != 1)
						num.erase(num.begin());
					v.push_back(num);
				}
				num = "";
			}
		}
		if (num != "")
		{
			while (num[0] == '0' && num.size() != 1)
				num.erase(num.begin());
			v.push_back(num);
		}
	}

	sort(v.begin(), v.end(),[](string s1,string s2){
		if (s1.size() == s2.size())
			return s1 < s2;
		return s1.size() < s2.size();
	});

	for (string s : v) {
		cout << s << '\n';
	}
	return 0;
}