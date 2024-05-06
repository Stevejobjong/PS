#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		bool err = false;
		string str;
		stack<char> s;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				s.push(str[i]);
			else if (!s.empty())
				s.pop();
			else {
				err = true;
				break;
			}
		}
		if (s.empty()&&!err)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}