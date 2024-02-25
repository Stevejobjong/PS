#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n[9];
	for (int i = 0; i < 9; i++) {
		cin >> n[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			int sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j)
					sum += n[k];
			}
			if (sum == 100)
			{
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)
						n[k] = 0;
				}
				sort(n, n + 9);
				for (int k = 0; k < 9; k++) {
					if (n[k] != 0)
						cout << n[k] << '\n';

				}
				return 0;
			}
		}
	}

	return 0;
}