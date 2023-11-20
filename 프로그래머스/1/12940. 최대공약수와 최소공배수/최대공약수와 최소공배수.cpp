#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    int tmp = 1;
    int num = n * m;
    while (tmp != 0) {
		tmp = n % m;
		n = m;
		m = tmp;
    }
    tmp = num / n;
    return {n,tmp};
}