#include <iostream>
#include <cmath>
using namespace std;


int solution(int n, int a, int b)
{
	int answer = 0;
	while (n != 1) {
		n /= 2;
		answer++;
		a = (int)ceil((float)a / 2);
		b = (int)ceil((float)b / 2);
		if (a == b)
			return answer;
	}
}