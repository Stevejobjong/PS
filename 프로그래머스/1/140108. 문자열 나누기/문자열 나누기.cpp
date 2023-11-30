#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
	char curC = 0;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (curC == NULL) {
			curC = s[i];
			cnt1++;
		}
		else if (curC == s[i]) {
			cnt1++;
		}
		else if (curC != s[i]) {
			cnt2++;
		}
		if (cnt1 == cnt2) {
			curC = 0;
			cnt1 = 0;
			cnt2 = 0;
			answer++;
		}
	}
	if (cnt1 + cnt2 > 0)
		answer++;
    return answer;
}