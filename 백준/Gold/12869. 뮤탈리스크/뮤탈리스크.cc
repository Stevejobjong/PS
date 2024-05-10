#include<bits/stdc++.h>
using namespace std;

int scv[3];
vector<int> d = { 1,3,9 };
int visited[62][62][62];
struct A {
	int a, b, c;
};
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> scv[i];
	}
	queue<A> q;
	q.push({ scv[0],scv[1],scv[2] });
	while (q.size())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		do {
			int na = a - d[0];
			int nb = b - d[1];
			int nc = c - d[2];
			if (na < 0)
				na = 0;
			if (nb < 0)
				nb = 0;
			if (nc < 0)
				nc = 0;
			if (!visited[na][nb][nc])
			{
				visited[na][nb][nc] = visited[a][b][c] + 1;
				if (na + nb + nc == 0)
					break;
				q.push({ na,nb,nc });
			}

		} while (next_permutation(d.begin(), d.end()));
	}


	cout << visited[0][0][0];

	return 0;
}