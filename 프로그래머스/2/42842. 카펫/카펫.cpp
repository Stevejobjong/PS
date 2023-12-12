#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
	int sum = brown + yellow;	
	for (int h = 1; h <= sqrt(yellow); h++) {
		if (yellow % h == 0) {
			int w = yellow / h;
			if (sum == (w + 2) * (h + 2))
				return { w + 2,h + 2 };
		}
	}

	return { -1,-1 };
}