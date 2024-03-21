#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int maxi = -1;
	int sum = 0;
	float ans = 0.0f;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		sum += num;
		maxi = max(num, maxi);
	}
	ans = ((float)sum / maxi) * 100 / N;
	cout << ans;


	return 0;
}
