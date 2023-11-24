#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	priority_queue<int> q;
	priority_queue<int> tmp;
	for (int i = 0; i < score.size(); i++) {
		q.push(score[i]);
		tmp = q;
		if (q.size() < k) {
			for (int j = 0; j < q.size() - 1; j++)
				tmp.pop();
			answer.push_back(tmp.top());
		}
		else {
			for (int j = 0; j < k - 1; j++)
				tmp.pop();
			answer.push_back(tmp.top());
		}
	}

	return answer;
}