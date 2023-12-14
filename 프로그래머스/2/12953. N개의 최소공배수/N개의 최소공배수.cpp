#include <string>
#include <vector>

using namespace std;

int GCD(int num1, int num2) {
	int tmp = -1;
	while (tmp!=0) {
		tmp = num1 % num2;
		num1 = num2;
		num2 = tmp;
		if (tmp == 0)
			return num1;
	}
}

int LCM(int num1, int num2) {
	return num1 * num2 / LCM(num1, num2);
}

int solution(vector<int> arr) {
	int answer = 0;
	answer = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		answer = LCM(answer, arr[i]);
	}
	return answer;
}
