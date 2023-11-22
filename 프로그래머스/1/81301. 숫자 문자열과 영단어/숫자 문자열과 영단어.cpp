#include <bits/stdc++.h>

using namespace std;


int solution(string s) {
	int n = s.size();
	int answer = 0;
	string str = "";
	map<string, int> m;
	m["zero"] = 1;
	m["one"] = 2;
	m["two"] = 3;
	m["three"] = 4;
	m["four"] = 5;
	m["five"] = 6;
	m["six"] = 7;
	m["seven"] = 8;
	m["eight"] = 9;
	m["nine"] = 10;
	int i = 0;
	while (s != "") {
		if (m[str] > 0) {
			s.erase(s.find(str), str.size());
			answer *= 10;
			answer += m[str]-1;
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