#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int n = number.size();
    for (int i = 0; i < n; i++) {
        int num = number[i];
        for (int j = i + 1; j < n; j++) {
            num += number[j];
            for (int k = j + 1; k < n; k++) {
                if (num + number[k] == 0)
                    answer++;
            }
            num -= number[j];
        }
    }
    return answer;
}