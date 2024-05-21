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
		int N, M;
		cin >> N >> M;
		int i = 1;
		int result = 1;
		while (N--)
		{
			result *= M--;
			result /= i++;
		}
		cout << result << '\n';
	}

	return 0;
}