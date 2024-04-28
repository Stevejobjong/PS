#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) 
	{
		int two = 0;
		int five = 0;
		int  N = 0;
		cin >> N;

		for (int i = 2; i <= N; i *= 2)
		{
			two += N / i;
		}
		for (int i = 5; i <= N; i *= 5)
		{
			five += N / i;
		}
		cout << min(two, five) << '\n';
	}

	return 0;
}