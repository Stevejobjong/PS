#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	vector<string> pronunciation = { "aya","ye","woo","ma" };
	int answer = 0;
	int before = 0;
	for (int i = 0; i < babbling.size(); i++) {
		before = 0;
		for (int j = 0; j < babbling[i].size();) {
			if (before != 1 && babbling[i].compare(j, 3, pronunciation[0]) == 0) { j += 3; before = 1; }
			else if (before != 2 && babbling[i].compare(j, 2, pronunciation[1]) == 0) { j += 2; before = 2; }
			else if (before != 3 && babbling[i].compare(j, 3, pronunciation[2]) == 0) { j += 3; before = 3; }
			else if (before != 4 && babbling[i].compare(j, 2, pronunciation[3]) == 0 ) { j += 2; before = 4; }
			else { before = 0; break; }
		}
		if (before) answer++;
	}
	return answer;
}