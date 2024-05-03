#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long axis = 0;
    long long rad1 = (long long)r1 * r1;
    long long rad2 = (long long)r2 * r2;
    for (long long x = 1; x <= r2; x++) {
        long long y1;
        long long y2 = rad2 - x * x;
        if (x < r1) {
            y1 = ceil(sqrt(rad1 - x * x));
        }
        else
            y1 = 0;
        y2 = floor(sqrt(rad2 - x * x));
        answer += y2 - y1 + 1;
    }
    answer = 4 * (axis + answer);
    return answer;
}