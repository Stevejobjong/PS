#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
	for (int i = 0; i < progresses.size(); i++) {
		int cnt = 1;
		int day = (int)ceil((float)(100 - progresses[i]) / speeds[i]);
		bool release = true;
        
		for (int j = i + 1; j < progresses.size(); j++) {
			progresses[j] += day * speeds[j];
            
			if (progresses[j] >= 100 && release) {
				i++;
				cnt++;
			}
			else
				release = false;
		}
        
		answer.push_back(cnt);
	}
    
    return answer;
}