#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer=0;
    int n = s.size();
    int sign = 1;
    if(s[0] == '-')
        sign=-1;
    for(int i = 0 ; i < n ; i++) {
        if('0' <= s[i] && s[i] <= '9'){
            answer*=10;
            answer+=s[i]-'0';
        }            
    }
        
    return answer*sign;
}