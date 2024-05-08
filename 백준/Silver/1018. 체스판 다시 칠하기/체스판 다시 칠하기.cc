#include <iostream>
using namespace std;

int main(void) {
	char chess[51][51];
	char color[2] = { 'W','B' };		//W=0,B=1
	int N, M;
	int cnt = 0;
	int min = 100;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chess[i][j];
		}
	}

	for (int i = 0; i < N-7; i++) {
		for (int j = 0; j < M - 7; j++) {
			cnt = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					//White
					if (chess[i + k][ j + l] != color[(k + l) % 2])
						cnt++;
				}
			}
			if (min > cnt)
				min = cnt;
			cnt = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					//Black
					if (chess[i + k][j + l] == color[(k + l) % 2])
						cnt++;
				}
			}
			if (min > cnt)
				min = cnt;
		}

	}
	cout << min;

	return 0;
}