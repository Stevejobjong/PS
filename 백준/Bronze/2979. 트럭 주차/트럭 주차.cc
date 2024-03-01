#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int answer = 0;
	int park[100] = { 0, };
	int A, B, C;
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		for (int t = start; t < end; t++) {
			park[t]++;
		}
	}
	for (int i = 0; i < 100; i++) {
		switch (park[i]) {
		case 1:
			answer += A;
			break;
		case 2:
			answer += 2 * B;
			break;
		case 3:
			answer += 3 * C;
			break;
		defualt:
			break;
		}
	}
	cout << answer;

	return 0;
}