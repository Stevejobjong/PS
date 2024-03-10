#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int pos;
	string pattern;
	string pre;
	string suf;
	cin >> N;
	cin >> pattern;
	pos = pattern.find('*');
	pre = pattern.substr(0, pos);
	suf = pattern.substr(pos + 1);

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (pre.size() + suf.size() > str.size())
			cout << "NE\n";
		else {

			if (pre == str.substr(0, pre.size()) && suf == str.substr(str.size() - suf.size()))
				cout << "DA\n";
			else
				cout << "NE\n";
		}
	}

	return 0;
}