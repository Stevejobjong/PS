#include <bits/stdc++.h>
using namespace std;
vector<string> split(string input, string delimeter)
{
	vector<string> ret;
	long long pos = 0;
	while ((pos = input.find(delimeter)) != string::npos)
	{
		ret.push_back(input.substr(0, pos));
		input.erase(0, pos + delimeter.length());
	}
	ret.push_back(input);
	return ret;
}
vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
	vector<int> ans;
	map<string, int> m;
	map<string, set<string>> r;	//key:신고당한사람, value:신고한사람 목록
	for (auto i : report)
	{
		vector<string> v = split(i," ");
		r[v[1]].insert(v[0]);
	}
	for (auto i : r)
	{
		if (i.second.size() >= k)
		{
			for (auto j : i.second)
				m[j]++;
		}
	}
	for (auto i : id_list)
	{
		ans.push_back(m[i]);
	}

	return ans;
}
/*#include <bits/stdc++.h>

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
}*/