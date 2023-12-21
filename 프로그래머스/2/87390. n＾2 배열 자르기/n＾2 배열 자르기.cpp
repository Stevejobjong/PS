#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;
	int row;
	int col;

	for (long long i = left; i < right + 1; i++) {
		row = i / n;
		col = i % n;

		answer.push_back(max(row,col) + 1);
	}
	return answer;
}