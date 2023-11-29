#include <bits/stdc++.h>

using namespace std;

string solution(string X, string Y) {
	string answer = "";
	map<char, int> mX;
	map<char, int> mY;
	sort(X.begin(), X.end(), greater<char>());
	sort(Y.begin(), Y.end(), greater<char>());

	for (int i = 0; i < X.size(); i++) {
		mX[X[i]]++;
	}
	for (int i = 0; i < Y.size(); i++) {
		mY[Y[i]]++;
	}
	for (int i = 9; i >= 0; i--) {
		int n = min(mX['0' + i], mY['0' + i]);
		for (int j = 0; j < n; j++)
			answer += '0' + i;
	}


	if (answer != "") {
		while (answer[0] == '0' && answer.size() != 1)
			answer.erase(answer.begin() + 0);
		return answer;
	}
	else
		return "-1";
}