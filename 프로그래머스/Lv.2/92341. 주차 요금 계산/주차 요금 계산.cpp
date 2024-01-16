#include <bits/stdc++.h>

using namespace std;

int ToMinute(string str) {
	int hour = stoi(str.substr(0, 2)) * 60;
	return hour + stoi(str.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map<string, int> m;
	map<string, int> t;
	for (auto rec : records) {
		rec += ' ';
		string tmp = "";
		int idx = 0;
		string recArr[3];
		for (int i = 0; i < rec.size(); i++) {
			if (rec[i] == ' ' && !tmp.empty()) {
				recArr[idx++] = tmp;
				tmp = "";
			}
			else {
				tmp += rec[i];
			}
		}
		if (idx == 3) {			
			if (recArr[2] == "IN") {
				m[recArr[1]]= ToMinute(recArr[0]);
			}
			else {
				t[recArr[1]] += ToMinute(recArr[0]) - m[recArr[1]];
				m.erase(recArr[1]);
			}
		}
	}
	for (auto rec : m) {
		t[rec.first] += ToMinute("23:59") - rec.second;
	}
	for (auto time : t) {
		if (time.second - fees[0] < 0)
			answer.push_back(fees[1]);
		else {
			answer.push_back(fees[1] + (int)ceil((float)(time.second - fees[0]) / fees[2]) * fees[3]);
		}
	}

	return answer;
}