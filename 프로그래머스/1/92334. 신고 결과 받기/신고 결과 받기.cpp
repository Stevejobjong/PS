#include <bits/stdc++.h>

using namespace std;


vector<string> Split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    vector<int> answer;
    map<string, int> repCnt;
    map<string, set<string>> m;
    for (int i = 0; i < report.size(); i++) {
        vector<string> spl = Split(report[i], ' ');
        m[spl[1]].insert(spl[0]);
    }
    for (int i = 0; i < id_list.size(); i++) {
        if (m[id_list[i]].size() >= k) {
            for (auto j : m[id_list[i]]) {
                repCnt[j]++;
            }
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(repCnt[id_list[i]]);
    }
	return answer;
}