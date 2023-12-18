#include <bits/stdc++.h>

using namespace std;

bool IsCollect(string s) {
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case '[':
		case '(':
		case '{':
			stk.push(s[i]);
			break;
		case ']':
			if (stk.empty() || stk.top() != '[')
				return false;
			else
				stk.pop();
			break;
		case ')':
			if (stk.empty() || stk.top() != '(')
				return false;
			else
				stk.pop();
			break;
		case '}':
			if (stk.empty() || stk.top() != '{')
				return false;
			else
				stk.pop();
			break;
		}
	}
    if(stk.empty())
        return true;
    else
        return false;
}

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.size(); i++) {
		if (IsCollect(s))
			answer++;
		s.push_back(s[0]);
		s.erase(s.begin());
	}
	return answer;
}