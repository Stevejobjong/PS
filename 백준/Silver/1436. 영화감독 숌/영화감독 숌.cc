#include<bits/stdc++.h>
using namespace std;

int main(void) 
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int num = 0;
	while (N) 
	{
		num++;
		int tmp = num;
		int cnt = 0;
		bool isEnd = false;
		while (tmp > 0)
		{
			if (tmp % 10 == 6)
				cnt++;
			else
				cnt = 0;
			if (cnt >= 3)
			{
				isEnd = true;
				break;
			}
			tmp /= 10;
		}
		if (isEnd)
		{
			N--;
		}
	}
	cout << num;
	return 0;
}