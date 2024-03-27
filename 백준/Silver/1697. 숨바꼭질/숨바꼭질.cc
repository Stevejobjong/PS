#include <bits/stdc++.h>
using namespace std;
vector<string> split(string input, string delimeter) {
	vector<string> ret;
	long long pos = 0;
	while ((pos = input.find(delimeter)) != string::npos) {
		ret.push_back(input.substr(0, pos));
		input.erase(0, pos + delimeter.length());
	}
	ret.push_back(input);
	return ret;
}

int visited[100001];
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int K;
	int cnt = 1;
	queue<int> q;
	cin >> N >> K;

	if (N == K)
	{
		cout << 0;
		return 0;
	}

	q.push(N);
	visited[N] = 1;

	while (!q.empty())
	{
		int num = q.front(); q.pop();
		for (int i = 0; i < 3; i++)
		{
			int Next;
			cnt = visited[num];
			switch (i)
			{
			case 0:
				Next = num - 1;
				break;
			case 1:
				Next = num + 1;
				break;
			case 2:
				Next = num * 2;
				break;
			}
			if (Next >= 0 && Next <= 100000 && !visited[Next])
			{
				q.push(Next);
				visited[Next] = cnt + 1;
				if (Next == K)
				{
					cout << visited[K]-1;
					return 0;
				}
			}
		}
		cnt++;
	}

	return 0;
}