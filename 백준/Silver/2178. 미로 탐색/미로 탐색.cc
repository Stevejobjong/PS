#include<iostream>
#include<queue>
using namespace std;

int map[101][101];
int visited[101][101];
int n, m;
int idx = 0;
int dist[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	dist[1][1] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (!visited[newX][newY] && map[newX][newY]) {
				visited[newX][newY] = 1;
				q.push(make_pair(newX, newY));
				dist[newX][newY] = dist[x][y] + 1;
			}
		}
	}

}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str="";
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			map[i][j + 1] = str[j] - '0';
	}
	bfs();
	cout << dist[n][m];
	return 0;
}