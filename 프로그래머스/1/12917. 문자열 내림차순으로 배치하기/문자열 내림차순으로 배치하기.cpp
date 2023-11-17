#include <bits/stdc++.h>

using namespace std;

bool cmp(const char a, const char b) {
    bool isA = isupper(a);
    bool isB = isupper(b);
    if (isA && !isB)
        return false;
    else if (!isA && isB)
        return true;
    else {
        return a > b;
    }
}
string solution(string s) {
    sort(s.begin(), s.end(), cmp);
    return s;
}