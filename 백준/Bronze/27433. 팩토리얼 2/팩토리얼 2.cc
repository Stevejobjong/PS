#include<bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << factorial(N);

	return 0;
}