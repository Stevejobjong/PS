#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> w;
unordered_map<string, int> m;
bool IsCorrect() {
	bool result = true;
	for (auto j : w) {
		if (m[j.first] != j.second) {
			result = false;
			break;
		}
	}
	return result;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int cnt = 0;

    for (int i = 0; i < want.size(); i++) {
        w[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size(); i++) {

		if (cnt < 10) {
			m[discount[i]]++;
			cnt++;
        }
        else if (cnt == 10) {
            if (IsCorrect())
                answer++;
            m[discount[i - 10]]--;
            m[discount[i]]++;
        }
    }
    if (IsCorrect())
        answer++;
    return answer;
}
