#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	int RT = 0;
	int CF = 0;
	int JM = 0;
	int AN = 0;
	for (int i = 0; i < survey.size(); i++) {
		if (survey[i][0] == 'R')
			RT += choices[i] - 4;
		else if (survey[i][1] == 'R')
			RT += 4 - choices[i];
		if (survey[i][0] == 'C')
			CF += choices[i] - 4;
		else if (survey[i][1] == 'C')
			CF += 4 - choices[i];
		if (survey[i][0] == 'J')
			JM += choices[i] - 4;
		else if (survey[i][1] == 'J')
			JM += 4 - choices[i];
		if (survey[i][0] == 'A')
			AN += choices[i] - 4;
		else if (survey[i][1] == 'A')
			AN += 4 - choices[i];
	}
	if (RT > 0)
		answer += 'T';
	else
		answer += 'R';
	if (CF > 0)
		answer += 'F';
	else
		answer += 'C';
	if (JM > 0)
		answer += 'M';
	else
		answer += 'J';
	if (AN > 0)
		answer += 'N';
	else
		answer += 'A';

	return answer;
}