#include <iostream>
using namespace std;

int main(void) {
	int num[9];
	int index,max=0;
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 9; i++) {
		if (max < num[i]) {
			max = num[i];
			index = i+1;
		}
	}
	cout << max << endl << index;
}