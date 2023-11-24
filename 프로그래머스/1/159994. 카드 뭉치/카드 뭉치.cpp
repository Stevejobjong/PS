#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	int idx1 = 0;
	int idx2 = 0;
	for (int i = 0; i < goal.size(); i++) {
		if (idx1 < cards1.size() && goal[i] == cards1[idx1]) {
			idx1++;
		}
		else if (idx2 < cards2.size() && goal[i] == cards2[idx2]) {
			idx2++;
		}
		else
			return "No";
	}

	return "Yes";
}