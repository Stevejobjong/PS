#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
	set<int> s;
	for (int i = 1; i <= elements.size(); i++) {
		for (int j = 0; j < elements.size(); j++) {
			int sum = 0;
			for (int k = j; k < j + i; k++) {
				if (k > elements.size() - 1)
					sum += elements[k - elements.size()];
				else
					sum += elements[k];
			}
			s.insert(sum);
		}
	}
	return s.size();
}