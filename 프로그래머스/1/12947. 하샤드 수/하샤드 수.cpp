#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int num = 0;
    int origin = x;
    while (x != 0) {
        num += x % 10;
        x /= 10;
    }
    return origin % num == 0 ? true : false;
}