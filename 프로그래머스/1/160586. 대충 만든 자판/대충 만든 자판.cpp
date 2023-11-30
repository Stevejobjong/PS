#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;
	for (int i = 0; i < targets.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < targets[i].size(); j++) {
			char target = targets[i][j];
			int mini = 101;
			for (int k = 0; k < keymap.size(); k++) {
				auto it = find(keymap[k].begin(),keymap[k].end(),target);
				if (it != keymap[k].end())
					mini = min(mini, (int)(it - keymap[k].begin() + 1));
			}
			if (mini == 101) {
				answer.push_back({ -1 });
                cnt=0;
				break;
			}
			cnt += mini;
		}
		if(cnt!=0)
			answer.push_back(cnt);
	}
	return answer;
}