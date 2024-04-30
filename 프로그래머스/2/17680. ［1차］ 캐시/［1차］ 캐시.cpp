#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> v;

	for (string str : cities) 
	{
		bool hit = false;
		int size = v.size();
		for (int i = 0; i < size; i++) {
			transform(str.begin(), str.end(), str.begin(), ::tolower);
			transform(v[i].begin(), v[i].end(), v[i].begin(), ::tolower);
			if (str == v[i])
			{
				answer += 1;
				hit = true;
				v.push_back(v[i]);
				v.erase(v.begin() + i);
                break;
			}
		}
		if (!hit)
		{
			answer += 5;
			v.push_back(str);
			if (v.size() > cacheSize)
				v.erase(v.begin());
		}
	}

	return answer;
}