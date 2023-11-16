#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int a, int b) {
    if(a==b)
        return a;
    long long answer = 0;
    int l = min(a,b);
    int r = max(a,b);
    for(int i=l;i<=r;i++){
        answer+=i;
    }
    
    return answer;
}