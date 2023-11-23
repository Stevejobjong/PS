#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> food) {
	string answer = "";
	for (int i = 1; i < food.size(); i++) {
		if (food[i] % 2 != 0)
			food[i]--;
		for (int j = 0; j < food[i]/2; j++) {
			answer += to_string(i);
		}
	}
	string tmp = answer;
	sort(tmp.begin(), tmp.end(), greater<char>());
	answer += '0';
	answer += tmp;

	return answer;
}