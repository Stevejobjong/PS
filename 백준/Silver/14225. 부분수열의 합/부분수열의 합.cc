#include <bits/stdc++.h>
using namespace std;

int visited[20];
int num[2000001];
int N;
vector<int> v;
void Recursion(int sum,int index) {
	num[sum] = 1;

	for (int i = index; i < N; i++) {
		if (!visited[i])
		{
			visited[i] = 1;
			Recursion(sum + v[i],i+1);
			visited[i] = 0;
		}
	}
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num[n] = 1;
		v.push_back(n);
	}
	Recursion(0, 0);    
	long long cnt = 1;
	while(1)
	{
		if (num[cnt] == 0)
		{
			cout << cnt;
			return 0;
		}
		cnt++;
	}
	return 0;
}