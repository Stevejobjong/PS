#include <bits/stdc++.h>

using namespace std;
bool visited[8];

int dfs(int n,int k, vector<vector<int>> d,int cnt) {
	visited[n] = true;
	k -= d[n][1];
	int m = cnt;
	for (int i = 0; i < d.size(); i++) {
		if (!visited[i] && k >= d[i][0]) {
			m = max(m, dfs(i, k, d, cnt + 1));
			visited[i] = false;
		}
	}
	return m;
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	for (int i = 0; i < dungeons.size(); i++) {
		memset(visited, 0, sizeof(visited));
		if (k >= dungeons[i][0]) {
			answer = max(answer, dfs(i, k, dungeons, 1));
		}
	}

	return answer;
}