#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	unordered_map<int, int> m;
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			if (m[numbers[i] + numbers[j]] == 0)
				m[numbers[i] + numbers[j]]++;
		}
	}
	for (auto it : m)
		answer.push_back(it.first);
	sort(answer.begin(), answer.end());

	return answer;
}