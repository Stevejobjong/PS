#include <bits/stdc++.h>
using namespace std;

int words[51];
int N, K;
int count(int mask) {
    int cnt = 0;
    for (int word : words) {
        if (word && (word & mask) == word)cnt++;
    }
    return cnt;
}
int go(int index, int k, int mask) {
    if (k < 0) return 0;
    if (index == 26) return count(mask);
    int ret = go(index + 1, k - 1, mask | (1 << index)); //index번째 알파벳 읽기
    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
        ret = max(ret, go(index + 1, k, mask)); //index번째 알파벳 건너뛰기
    }
    return ret;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (char c : str) {
            words[i] |= (1 << (c - 'a'));
        }
    }
    cout << go(0, K, 0) << '\n';
    return 0;
}