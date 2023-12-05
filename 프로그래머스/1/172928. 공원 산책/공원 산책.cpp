#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int w=0, h=0;
    int curW = 0, curH = 0;
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j] == 'S')
            {
                w = j;
                h = i;
            }
        }
    }
    curW = w;
    curH = h;
    for (int i = 0; i < routes.size(); i++) {
        char dir='a';
        int distance = 0;
        for (int j = 0; j < routes[i].size(); j++) {
            dir = routes[i][0];
            distance = routes[i][2] - '0';                        
        }
        switch (dir) {
        case 'N':
            for (int j = 0; j < distance; j++) {
                h--;
                if (h < 0) {
                    h = curH;
                    break;
                }
                if (park[h][w] == 'X') {
                    h = curH;
                    break;
                }
            }
            curH = h;
            break;
        case 'S':
            for (int j = 0; j < distance; j++) {
                h++;
                if (h == park.size()) {
                    h = curH;
                    break;
                }
                if (park[h][w] == 'X') {
                    h = curH;
                    break;
                }
            }
            curH = h;
            break;
        case 'W':
            for (int j = 0; j < distance; j++) {
                w--;
                if (w < 0) {
                    w = curW;
                    break;
                }
                if (park[h][w] == 'X') {
                    w = curW;
                    break;
                }
            }
            curW = w;
            break;
        case 'E':
            for (int j = 0; j < distance; j++) {
                w++;
                if (w == park[0].size()) {
                    w = curW;
                    break;
                }
                if (park[h][w] == 'X') {
                    w = curW;
                    break;
                }
            }
            curW = w;
            break;

        }

    }
    return {h,w};
}