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
string solution(string s) {
    string answer = "";
    int sign = 1;
    int minnum = 0;
    int maxnum = 0;
    vector<string> spl = Split(s, ' ');
    minnum = stoi(spl[0]);
    maxnum = stoi(spl[0]);
    for (int i = 1; i < spl.size(); i++) {
        int num = stoi(spl[i]);
        minnum = min(minnum, num);
        maxnum = max(maxnum, num);
    }
    answer += to_string(minnum);
    answer += ' ';
    answer += to_string(maxnum);
    return answer;
}