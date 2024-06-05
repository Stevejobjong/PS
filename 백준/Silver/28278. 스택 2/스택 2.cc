#include<bits/stdc++.h>

using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	stack<int> s;
	cin >> N;
	while (N--)
	{
		int op;
		cin >> op;
		switch (op)
		{
		case 1:
			int num;
			cin >> num;
			s.push(num);
			break;
		case 2:
			if (s.empty())
				cout << -1 << '\n';
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
			break;
		case 3:
			cout << s.size() << '\n';;
			break;
		case 4:
			cout << (int)s.empty() << '\n';;
			break;
		case 5:
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
			break;
		}
	}
	return 0;
}