#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	int day[12] = {0, 31,29,31,30,31,30,31,31,30,31,30};
	int tmp = 0;
	string week[7] = { "FRI","SAT","SUN","MON","TUE","WED","THU" };
	for (int i = 0; i < a; i++) {
		tmp += day[i];
	}
	tmp += b - 1;
	tmp %= 7;
	week[tmp];
	return week[tmp];
}