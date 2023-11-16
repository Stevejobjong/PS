#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    int n=numbers.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=numbers[i];
    }
    answer = (double)sum/n;
    return answer;
}