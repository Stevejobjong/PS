#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int curWeight = 0;
	int time = 0;
	int i = 0;
	deque<pair<int, int>> q;

	while (i<truck_weights.size()) {
		for (int j = 0; j < q.size(); j++) {
			q[j].second++;
		}
		if (!q.empty() && q.front().second > bridge_length)
		{
			curWeight -= q.front().first;
			q.pop_front();
		}

		if (truck_weights[i] + curWeight <= weight)
		{
			curWeight += truck_weights[i];
			q.push_back({ truck_weights[i++],1 });
		}
		time++;
	}
	time += bridge_length;
    
    return time;
}