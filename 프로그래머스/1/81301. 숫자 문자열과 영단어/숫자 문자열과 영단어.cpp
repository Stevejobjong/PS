#include <bits/stdc++.h>

using namespace std;
int solution(string s) {
	int n = s.size();
	int answer = 0;
	string str = "";
	map<string, int> m;
	m["zero"] = 0;
	m["one"] = 1;
	m["two"] = 2;
	m["three"] = 3;
	m["four"] = 4;
	m["five"] = 5;
	m["six"] = 6;
	m["seven"] = 7;
	m["eight"] = 8;
	m["nine"] = 9;
	int i = 0;
	while (s != "") {
		if (m[str] > 0) {
			s.erase(s.find(str), str.size());
			answer *= 10;
			answer += m[str];
			str = "";
			i = 0;
			continue;
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			answer *= 10;
			answer += s[i] - '0';
			s.erase(0, 1);
			i = 0;
			continue;
		}
		else {
			str += s[i];
		}
		i++;
	}
	return answer;
}