#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
long long solution(int n, vector<int> times) {
	long long answer = 0;
	vector<long long> v;
	map<int, int> m;
	for (int i = 0; i < times.size(); i++) {
			v.push_back(times[i]);
			m[times[i]] = 2;
	}

	while (v.size() < n) {
		int mn = 1000000001;
		int mnNum = -1;
		for (auto i : m) {
			if (mn > i.first * i.second)
			{
				mn = i.first * i.second;
				mnNum = i.first;
			}
		}
		v.push_back(mn);
		m[mnNum]++;
	}

	answer = v[n - 1];

	return answer;
}