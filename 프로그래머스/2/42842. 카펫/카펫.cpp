#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
	int w, h;
	int sum = brown + yellow;
	for (int h = 3; h <= yellow + 2; h++)
	{
		if (sum % h == 0)
		{
			w = sum / h;
			if (yellow == (h - 2) * (w - 2))
				return { w,h };
		}
	}
}