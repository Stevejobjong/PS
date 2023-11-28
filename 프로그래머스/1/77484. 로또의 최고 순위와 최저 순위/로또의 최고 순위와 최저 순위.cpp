#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    	vector<int> answer;
	int zerocnt = 0;
	int cnt = 0;
	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) {
			zerocnt++;
			continue;
		}

		for (int j = 0; j < win_nums.size(); j++) {
			if (lottos[i] == win_nums[j]) {
				cnt++;
				break;
			}
		}
	}
	return{ 7 - (cnt + zerocnt)> 6 ? 6 : 7 - (cnt + zerocnt),(7 - cnt > 6 ? 6 : 7 - cnt) };
}