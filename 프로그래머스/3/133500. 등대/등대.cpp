#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N;
vector<int> g[MAX_N + 1];
int dp[MAX_N + 1][2];
bool visited[MAX_N + 1];

int calc(int node, int idx) { // idx 0: node 꺼짐, 1: node 켜짐
	if (dp[node][0] != -1) return dp[node][idx];

	dp[node][0] = 0;
	dp[node][1] = 1;
	visited[node] = true;

	for (int child : g[node]) {
		if (visited[child]) continue; // 부모

		dp[node][0] += calc(child, 1);
		dp[node][1] += min(calc(child, 0), calc(child, 1));
	}

	return dp[node][idx];
}
int solution(int n, vector<vector<int>> lighthouse) {
	N = n;
	for (int i = 1; i <= N; i++) dp[i][0] = -1;

	for (vector<int> curr : lighthouse) {
		g[curr[0]].push_back(curr[1]);
		g[curr[1]].push_back(curr[0]);
	}
	
	int answer = min(calc(1, 0), calc(1, 1));
	return answer;
}