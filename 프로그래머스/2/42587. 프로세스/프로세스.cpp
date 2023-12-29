#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int,int>> q;
	int order = 1;
    
	for (int i = 0; i < priorities.size(); i++) {
		q.push_back({ i,priorities[i] });
	}
    
	while (true) {
		pair<int, int> f = q.front();
		q.pop_front();
		bool isProcessing = true;
        
		for (auto node : q)
		{
			if (node.second > f.second)
			{
				q.push_back(f);
				isProcessing = false;
                break;
			}
		}
        
		if (isProcessing) {
			if (f.first == location)
				return order;
			else
				order++;
		}
	}
    
    return order;
}