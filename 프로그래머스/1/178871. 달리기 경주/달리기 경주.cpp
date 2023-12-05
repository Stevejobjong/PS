#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string,int> m;
    for(int i=0;i<players.size();i++){
        m[players[i]]=i;
    }

    for (int i = 0; i < callings.size(); i++) {
        int rank = m[callings[i]];
        m[players[rank - 1]] += 1;
        m[callings[i]] -= 1;
        string tmp = players[rank - 1];
        players[rank - 1] = players[rank];
        players[rank] = tmp;
    }   
    
    return players;
}