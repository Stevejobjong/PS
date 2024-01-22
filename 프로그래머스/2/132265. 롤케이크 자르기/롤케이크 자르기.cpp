#include <string>
#include <vector>
#include <map>
using namespace std;
int solution(vector<int> topping) {
	int answer = 0;
	map<int, int> a;
	map<int, int> b;

	for (int i = 0; i < topping.size(); i++) {
		a[topping[i]]++;
	}

	for (int i = 0; i < topping.size(); i++) {
		b[topping[i]]++;
		a[topping[i]]--;
		if (a[topping[i]] == 0)
			a.erase(topping[i]);
		if (a.size() == b.size())
			answer++;
	}

	return answer;
}