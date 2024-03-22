#include <iostream>
using namespace std;

int main(void) {
	int a, b, v;
	int day = 0;
	int up = 0;
	cin >> a >> b >> v;

	up = a - b;
	day = (v - a) / up + 1;
	if ((v - a) % up > 0)
		day++;
	cout << day;

	return 0;
}
