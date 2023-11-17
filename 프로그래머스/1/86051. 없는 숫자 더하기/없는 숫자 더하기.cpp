#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int numCheck[10] = { 0, };
    for (int i = 0; i < numbers.size(); i++) {
        numCheck[numbers[i]]++;
    }

    for (int i = 0; i < sizeof(numCheck)/sizeof(int); i++) {
        if (numCheck[i] == 0)
            answer += i;
    }
    return answer;
}