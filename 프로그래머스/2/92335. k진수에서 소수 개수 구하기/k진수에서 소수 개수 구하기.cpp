#include <bits/stdc++.h>

using namespace std;

bool IsPrime(long long number) {
	if (number < 2)
		return false;
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}
int solution(int n, int k) {
	int answer = 0;
	string num = "";
	string tmp = "";
    while(n > 0) {
        num += to_string(n % k);
        n /= k;
    }
    reverse(num.begin(), num.end());
    
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == '0' && !tmp.empty()) {
			if (IsPrime(stoll(tmp)))
				answer++;
			tmp = "";
		}
		else {
			tmp += num[i];
		}
	}
    if(!tmp.empty()) {
        if(IsPrime(stoll(tmp)))
            answer++;
    }

	return answer;
}