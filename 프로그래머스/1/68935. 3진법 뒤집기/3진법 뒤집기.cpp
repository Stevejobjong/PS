#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp = 0;
    string str = "";
    while (n >= 3) {
        tmp = n % 3;
        str += to_string(tmp);
        n = n / 3;
    }
    str += to_string(n);
    int e = 0;
    for (int i = str.size()-1; i >= 0; i--) {
        answer += (str[i]-'0') * pow(3, e++);
    }
    return answer;
}