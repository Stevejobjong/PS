#include<bits/stdc++.h>

using namespace std;
vector<long long> a;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long K, N;
	long long sum = 0;
	vector<long long> v;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		long long t;
		cin >> t;
		a.push_back(t);
		sum += a[i];
	}
	long long left = 1;
	long long right = sum / N;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long tmp = 0;
		for (int i = 0; i < K; i++)
		{
			tmp += a[i] / mid;
		}
		if (tmp >= N)
		{
			v.push_back(mid);
			left = mid + 1;
		}
		else if (tmp < N)
		{
			right = mid - 1;
		}
	}
	sort(v.begin(), v.end(), greater<long long>());
	cout << v[0];
	return 0;
}