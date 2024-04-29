#include <bits/stdc++.h>
using namespace std;

bool IsPrime(long long num) {
	if (num < 2)
		return false;
	for (int i = 2; i <= sqrt(num); i++) 
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int solution(int n, int k) {
	int answer = 0;
	string str;
	while (n > 0)
	{
		str += to_string(n % k);
		n /= k;
	}
	reverse(str.begin(), str.end());
	long long num = 0;
	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] != '0')
		{
			num *= 10;
			num += str[i] - '0';
		}
		else
		{
			if (IsPrime(num))
				answer++;
			num = 0;
		}
	}
	if (IsPrime(num))
		answer++;
	return answer;
}