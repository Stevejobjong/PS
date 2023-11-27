#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<vector<int>> p(3);
	vector<pair<int, int>> cnt(3);
	cnt[0].first = 1;
	cnt[0].second = 0;
	cnt[1].first = 2;
	cnt[1].second = 0;
	cnt[2].first = 3;
	cnt[2].second = 0;

	p[0] = { 1,2,3,4,5 };
	p[1] = { 2,1,2,3,2,4,2,5 };
	p[2] = { 3,3,1,1,2,2,4,4,5,5 };

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == p[0][i % 5])
			cnt[0].second++;
		if (answers[i] == p[1][i % 8])
			cnt[1].second++;
		if (answers[i] == p[2][i % 10])
			cnt[2].second++;
	}
	sort(cnt.begin(), cnt.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second > b.second;
		});
	answer.push_back(cnt[0].first);
	for (int i = 1; i < 3; i++) {
		if (cnt[i].second != cnt[0].second)
			break;
		answer.push_back(cnt[i].first);
	}

	return answer;
}