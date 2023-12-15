#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	map<int, int> m;

	for (int i = 0; i < tangerine.size(); i++) {
		m[tangerine[i]]++;
	}

	vector<pair<int, int>> vec(m.begin(), m.end());

	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second)
			a.first > b.first;
		return a.second > b.second;
		});

	for (int i = 0; i < vec.size(); i++) {
		answer++;
		k -= vec[i].second;
		if (k <= 0)
			break;
	}

	return answer;
}