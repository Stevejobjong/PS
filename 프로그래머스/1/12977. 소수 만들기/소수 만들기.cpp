#include <bits/stdc++.h>
using namespace std;


int primeNum[3000];
int solution(vector<int> nums) {
	int answer = 0;
	for (int i = 2; i < 3000; i++) {
		primeNum[i] = i;
	}
	for (int i = 2; i < sqrt(3000); i++) {
		if (primeNum[i] == 0)
			continue;
		for (int j = i * i; j <= 3000; j += i)
			primeNum[j] = 0;
	}
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				if (primeNum[nums[i] + nums[j] + nums[k]] != 0)
					answer++;
			}
		}
	}

	return answer;
}