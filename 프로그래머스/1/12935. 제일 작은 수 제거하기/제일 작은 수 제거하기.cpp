#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    arr.erase(min_element(arr.begin(), arr.end()));
    if (arr.empty())
        return { -1 };
    return arr;
}