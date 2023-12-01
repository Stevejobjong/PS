#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
	stack<int> s;
	vector<int> v = { -1 };
	s.push(-1);
	int answer = 0;
	for (int x : ingredient) {
		if (s.top() == 1 && x == 2)
			s.top() = 12;
		else if (s.top() == 12 && x == 3)
			s.top() = 123;
		else if (s.top() == 123 && x == 1) {
			answer++;
			s.pop();
		}
		else
			s.push(x);
	}

	return answer;
}