#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> m;

	for (int i = 0; i < terms.size(); i++) {
		m[terms[i][0]] = stoi(terms[i].substr(2, terms[i].size() - 2));
	}
    
    int tod = 0;
    for (int i = 0; i < today.size(); i++) {
        if (today[i] != '.') {
            tod *= 10;
            tod += today[i] - '0';
        }
    }

    for (int i = 0; i < privacies.size(); i++) {
        int d = 0;
        for (int j = 0; j < 10; j++) {
            if (privacies[i][j] != '.') {
                d *= 10;
                d += privacies[i][j] - '0';
            }
        }
        int month = m[privacies[i][11]];
        while (month >= 12) {
            month -= 12;
            d += 10000;
        }
        d += month * 100;
        if (d % 10000 > 1300){
            d -= 1200;
            d += 10000;
        }
        if (d <= tod)
            answer.push_back(i+1);
    }
    return answer;
}
