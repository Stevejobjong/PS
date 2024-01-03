#include <string>
#include <vector>

using namespace std;
int ans;
void dfs(int n, vector<int> v, int t,int sum) {
	if (n >= v.size()){
		if(t == sum)
			ans++;
		return;
	}

	dfs(n + 1, v, t, sum + v[n]);
	dfs(n + 1, v, t, sum - v[n]);
}

int solution(vector<int> numbers, int target) {
	dfs(0, numbers, target, 0);
	return ans;
}