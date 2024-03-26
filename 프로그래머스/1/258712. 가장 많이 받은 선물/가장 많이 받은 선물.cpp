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

int solution(vector<string> friends, vector<string> gifts)
{
	int answer = -1;
	unordered_map<string, map<string,int>> send;	//누가 누구한테 몇번 선물했는지
	unordered_map<string, int> receive;			//선물받은 수
	unordered_map<string, int> giftVal;			//선물지수
	for (int i = 0; i < gifts.size(); i++)
	{
		vector<string> tmp = split(gifts[i], " ");
		string sender = tmp[0];
		string receiver = tmp[1];
		send[sender][receiver]++;
		receive[receiver]++;
	}
	for (int i = 0; i < friends.size(); i++)
	{
		int s = 0;
		for (auto j : send[friends[i]])
		{
			s += j.second;
		}
		giftVal[friends[i]] = s - receive[friends[i]];
	}
	for (auto i : friends)
	{
		int tmp = 0;
		for (auto j : friends)
		{
			if (i == j)
				continue;

			if (send[i][j] > send[j][i]) //i가 j한테 보낸 수가 더 크면
			{
				tmp++;
			}
			else if (send[j][i] == send[i][j])//같을때 선물지수로 비교
			{
				if (giftVal[i] > giftVal[j])
					tmp++;
			}
		}
		answer = max(answer, tmp);

	}
	return answer;
}