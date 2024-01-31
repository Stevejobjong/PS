#include <string>
#include <vector>

using namespace std;

bool visited[200];

void dfs(int idx, vector<vector<int>>& computers) {
	visited[idx] = true;
	for (int i = 0; i < computers[idx].size(); i++) {
		if (!visited[i] && computers[idx][i] == 1) {
			dfs(i, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			answer++;
			dfs(i, computers);
		}
	}

	return answer;
}