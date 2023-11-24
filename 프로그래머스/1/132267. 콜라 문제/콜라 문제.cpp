#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
	int ans = 0;
	while (n >= a) {
		n = n - a + b;
		ans += b;
	}
	return ans;
}