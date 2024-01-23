#include <string>
#include <vector>
#include <queue>
using namespace std;

int visited[1000001];
int solution(int x, int y, int n) {
	if (x == y)
		return 0;
	queue<pair<int, int>> q;

	visited[x] = true;
	q.push({ x, 0 });

	while (1) {
		if (q.empty())
			break;

		int nx = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nnx = 0;
			switch (i) {
			case 0:
				nnx = nx * 2;
				break;
			case 1:
				nnx = nx * 3;
				break;
			case 2:
				nnx = nx + n;
				break;
			}
			if (nnx == y) {
				return cnt + 1;
			}

			if (nnx > 1000000)
				continue;

			if (!visited[nnx]) {
				visited[nnx] = 1;
				q.push({ nnx,cnt + 1 });
			}
		}
	}
	return -1;
}