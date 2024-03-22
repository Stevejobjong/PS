#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string n;
	while (1)
	{
		cin >> n;
		bool isPel = true;
		if (n == "0")
			return 0;
		for (int i = 0; i < n.size()/2; i++)
		{
			if (n[i] != n[n.size() - i - 1])
			{
				isPel = false;
				break;
			}
		}
		if (isPel)
			cout << "yes\n";
		else
			cout << "no\n";

	}

	return 0;
}