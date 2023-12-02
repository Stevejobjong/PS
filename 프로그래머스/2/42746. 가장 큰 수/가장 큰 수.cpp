#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
	sort(numbers.begin(), numbers.end(), [=] (int a,int b) {
		string str1 = to_string(a);
		string str2 = to_string(b);
		return str1 + str2 > str2 + str1;
		});	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	while (answer[0] == '0' &&answer.size()!=1)
		answer.erase(answer.begin(),answer.begin()+1);
	return answer;
}