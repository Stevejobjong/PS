#include <iostream>
#include <cmath>
using namespace std;
int num[1000001];
int main(void) {
	int number;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int num1=0, num2=0;
	for (int i = 2; i <= 1000000; i++) {
		num[i] = i;
	}
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (num[i] == 0)
			continue;
		for (int j = i * 2; j <= 1000000; j = j + i) {
			num[j] = 0;
		}
	}
	while (true) {
		cin >> number;
		if (number == 0)
			return 0;
		
		for (int i = 2; i < number; i++) {
			if (num[i])
			{
				if (num[number - i])
				{
					num1 = i;
					num2 = number - i;
					break;
				}
			}

		}
		cout << number << " = " << num1 << " + " << num2<<'\n';
	}
	return 0;
}