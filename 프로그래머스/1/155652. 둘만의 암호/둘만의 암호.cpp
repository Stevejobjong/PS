#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    for(int i=0;i<s.size();i++){
        int cnt=index;
        while(cnt){
            s[i]+=1;
            if(s[i]>'z')
                s[i]='a';
            int check = skip.find(s[i]);
            if(check==string::npos)
                cnt--;            
        }
            
    }
    
    return s;
}