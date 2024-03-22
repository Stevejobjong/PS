#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

long long Func(int a, int b)
{
	if (b <= 1)
		return a % C;

	long long ret = Func(a, b / 2);
	ret = ret * ret % C;

	if (b % 2)
		ret = ret * a % C;

	return ret;
}


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> A >> B >> C;
	cout << Func(A, B);

	return 0;
}
