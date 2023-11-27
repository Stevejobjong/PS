#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    vector<int> v;
    v.resize(n + 1);
    for (int i = 0; i < section.size(); i++) {
        v[section[i]] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < section.size(); i++) {
        if (v[section[i]] == 1) {
            for (int j = 0; j < m; j++) {
                if (section[i] + j > n)
                    break;
                v[section[i] + j] = 0;
            }
            cnt++;
        }
    }
    return cnt;
}