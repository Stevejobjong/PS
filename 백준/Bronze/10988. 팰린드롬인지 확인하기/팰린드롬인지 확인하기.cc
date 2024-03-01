#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	for (int i = 0; i < str.size()/2; i++) 
	{
		if (str[i] != str[str.size() - 1 - i])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}