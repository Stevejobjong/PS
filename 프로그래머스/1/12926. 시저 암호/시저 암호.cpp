#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			answer += ' ';
		else if (isupper(s[i])) {
			if (s[i] + n > 'Z')
				s[i] = s[i] + n - 'Z' + 'A' - 1;
			else
				s[i] += n;
			answer += s[i];
		}
		else if (islower(s[i])) {
			if (s[i] + n > 'z')
				s[i] = s[i] + n - 'z' + 'a' - 1;
			else
				s[i] += n;
			answer += s[i];
		}
	}
	return answer;
}