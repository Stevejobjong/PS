#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int score[2] = { 0,0 };
	int winTime[2] = { 0,0 };
	int Endsec = 60 * 48;
	int prev = 0;
	int t = 0;
	cin >> N;
	while (N--) {
		string str;
		int team = -1;
		cin >> team;
		cin >> str;
		t = ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + (str[4] - '0');
		if (score[0] > score[1])
		{
			winTime[0] += t - prev;
		}
		else if (score[1] > score[0])
		{
			winTime[1] += t - prev;
		}
		score[team - 1]++;

		prev = t;
	}
	if (score[0] > score[1])
	{
		winTime[0] += Endsec - prev;
	}
	else if (score[1] > score[0])
	{
		winTime[1] += Endsec - prev;
	}
	for (int i = 0; i < sizeof(winTime)/sizeof(int); i++) {
		cout.width(2);
		cout.fill('0');
		cout << winTime[i] / 60;
		cout << ':';
		cout.width(2);
		cout.fill('0');
		cout << winTime[i] % 60;
		cout << '\n';
		//cout << format("{:02d}:{:02d}", winTime[i] / 60, winTime[i] % 60);
	}

	return 0;
}