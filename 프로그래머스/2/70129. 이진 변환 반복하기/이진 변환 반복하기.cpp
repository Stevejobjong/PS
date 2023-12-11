#include <string>
#include <vector>
#include <stack>
using namespace std;

string BinaryTranslator(int num) {
	if (num == 1)
		return "1";
	string result = "";
	stack<string> s;
	while (true) {
		s.push(to_string(num % 2));
		num /= 2;
		if (num == 1) {
			s.push("1");
			break;
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	return result;
}

vector<int> solution(string s) {
	vector<int> answer;
	int zeroCnt = 0;
	int currentZeroCnt = 0;
	int newSize = 0;
	int translateCnt = 0;
	while (s != "1") {
		translateCnt++;
		currentZeroCnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0')
				currentZeroCnt++;
		}
		zeroCnt += currentZeroCnt;
		newSize = s.size() - currentZeroCnt;
		s = BinaryTranslator(newSize);
	}

	return { translateCnt,zeroCnt };
}