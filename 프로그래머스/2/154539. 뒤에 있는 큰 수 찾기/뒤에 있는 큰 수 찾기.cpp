#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	stack<int> s;
	answer.resize(numbers.size());
	for (int i = numbers.size() - 1; i >= 0; i--) {

		while (!s.empty() && s.top() <= numbers[i])
			s.pop();

		if (s.empty())
			answer[i] = -1;
		else
			answer[i] = s.top();

		s.push(numbers[i]);
	}
	return answer;
}