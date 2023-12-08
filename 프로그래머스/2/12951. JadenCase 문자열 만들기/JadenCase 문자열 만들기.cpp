#include <bits/stdc++.h>

using namespace std;


string solution(string s) {
	bool isFirst = true;
	for (int i = 0; i < s.size(); i++) {

		if (s[i] <= '9' && s[i] >= '0') {
			isFirst = false;
			continue;
		}

		if (isFirst) {
			if (s[i] == ' ')
				continue;
			else {
				s[i] = toupper(s[i]);
				isFirst = false;
			}
		}
		else if (s[i] == ' ')
			isFirst = true;
		else
			s[i] = tolower(s[i]);
	}
	return s;
}