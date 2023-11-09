#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
	stack<int> stk;    
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			stk.push(1);
		else {
			if (stk.empty())
				return false;
			else
				stk.pop();
		}
	}
	return stk.empty() ? true : false;
}