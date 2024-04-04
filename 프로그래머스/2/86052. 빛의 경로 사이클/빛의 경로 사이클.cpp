#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int visited[501][501][4];
int length = 1;
void dfs(int i, int j, int dir, vector<string>& grid) {
    
	if (i < 0)
		i+=grid.size();
	if (j < 0)
		j += grid[0].size();
	i = i % grid.size();
	j = j % grid[0].size();
	if (visited[i][j][dir])
		return;
	visited[i][j][dir] = length++;
	int d = 0;
	int ni, nj;
	switch (grid[i][j]) {
	case 'S':
		d = dir;
		break;
	case 'L':
		d = (dir + 1) % 4;
		break;
	case 'R':
		d = (dir - 1) % 4;
		break;
	}
	d = d % 4;
	if (d < 0)
		d += 4;
	switch (d) {
	case 0:
		ni = i - 1;
		nj = j;
		break;
	case 1:
		ni = i;
		nj = j - 1;
		break;
	case 2:
		ni = i + 1;
		nj = j;
		break;
	case 3:
		ni = i;
		nj = j + 1;
		break;
	}
	dfs(ni, nj, d, grid);
}
vector<int> solution(vector<string> grid) {
	vector<int> answer;

	//d: 0상 1좌 2하 3우 로 빛쏘기
	for (int d = 0; d < 4; d++) {
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				int ni, nj;
				switch (d%4) {
				case 0:
					ni = i - 1;
					nj = j;
					break;
				case 1:
					ni = i;
					nj = j - 1;
					break;
				case 2:
					ni = i + 1;
					nj = j;
					break;
				case 3:
					ni = i;
					nj = j + 1;
					break;
				}
				dfs(ni, nj, d, grid);
				if (length != 1) {
					answer.push_back(length-1);
					length = 1;
				}
			}
		}
	}
    sort(answer.begin(),answer.end());
	return answer;
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solution({"SL","LR"});
	return 0;
}