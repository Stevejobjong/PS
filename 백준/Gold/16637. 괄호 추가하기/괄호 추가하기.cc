#include<bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> oper;
int ans = -987654321;
int calc(char op, int num1, int num2)
{
	switch (op)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	}
}
void Func(int idx,int calNum)
{
	if (idx == num.size() - 1)
	{
		ans = max(ans, calNum);
		return;
	}
	Func(idx + 1, calc(oper[idx], calNum, num[idx + 1]));

	if (idx + 2 <= num.size() - 1)
	{
		int tmp = calc(oper[idx + 1], num[idx + 1], num[idx + 2]);
		Func(idx + 2, calc(oper[idx], calNum, tmp));
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	string str;
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			num.push_back(str[i] - '0');
		}
		else
		{
			oper.push_back(str[i]);
		}
	}
	Func(0,num[0]);
	cout << ans;
	return 0;
}
