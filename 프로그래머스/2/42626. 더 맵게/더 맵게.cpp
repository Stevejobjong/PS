#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < scoville.size(); i++) {
		q.push(scoville[i]);
	}
    if(q.top()>=K)
        return 0;
    stack<int> s;
    while(!q.empty()) {
        if (s.empty()) {
            s.push(q.top());
            q.pop();
        }
        else {
			answer++;
			int food = s.top() + q.top() * 2;
			q.pop();
			s.pop();
			q.push(food);
			if (q.top() >= K)
				return answer;
        }
    }

    return -1;
}