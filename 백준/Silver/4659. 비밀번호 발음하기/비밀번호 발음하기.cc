#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	while (true) {
		bool first = false;// 모음 포함했으면 true
		bool second = true;// 모음 or 자음 3개 연속으로 오면 false
		bool third = true;// 같은 글자가 연속으로오면(ee,oo허용)
		int a = 0;
		cin >> str;
		if (str == "end")
			return 0;
		for (int i = 0; i < str.size(); i++) {
			char c = str[i];
			if (i >= 1 && str[i - 1] == c)
			{
				if (c != 'e' && c != 'o')
					third = false;
			}

			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
			{
				first = true;
				if (a > 0)
					a = 0;
				a--;
			}
			else 
			{
				if (a < 0)
					a = 0;
				a++;
			}
			
			if (abs(a) >= 3)
				second = false;
		}
		if (first && second && third)
			cout << '<' << str << '>' << " is acceptable.\n";
		else
			cout << '<' << str << '>' << " is not acceptable.\n";

	}


	return 0;
}