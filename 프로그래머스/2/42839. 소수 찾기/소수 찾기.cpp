#include <bits/stdc++.h>
using namespace std;
int NoPrime[10000000];
int visited[8];
int number[8];
vector<int> v;
int dfs(string num, int curNum) {
	if (!NoPrime[curNum]) {
		v.push_back(curNum);
	}

	for (int i = 0; i < num.size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(num, curNum * 10 + number[i]);
			visited[i] = 0;
		}
	}
	return 0;
}

int solution(string numbers) {
	int answer = 0;
	NoPrime[0] = 1;
	NoPrime[1] = 1;
	for (int i = 2; i < sqrt(10000000); i++) {
		for (int j = 2; j * i < 10000000; j++) {
			NoPrime[j * i] = 1;
		}
	}
	for (int i = 0; i <= numbers.size(); i++) {
		number[i] = numbers[i] - '0';
	}
	dfs(numbers,0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	answer = v.size();
	return answer;
}