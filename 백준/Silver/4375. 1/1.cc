#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int cnt = 1;
		int num = 1;
		while (1)
		{
			if (num % n == 0)
			{
				printf("%d\n", cnt);
				break;
			}
            else{                
				num = num * 10 + 1;
				num %= n;
				cnt++;
            }
		}
	}

	return 0;
}