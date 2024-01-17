#include <string>
#include <vector>

using namespace std;


char dict[5] = { 'A','E','I','O','U' };

int answer = 0;
int cnt = 0;
void dfs(string target, string cur) {
	if (cur.size() > 5)
	{
		cnt--;
		return;
	}
	if (target == cur)
		answer = cnt;

	for (int i = 0; i < 5; i++) {
		cnt++;
		dfs(target, cur + dict[i]);
	}
}

int solution(string word) {

	dfs(word, "");
	return answer;
}