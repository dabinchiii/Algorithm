#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 10000

using namespace std;

int N;
int wt[MAX_N + 1]; // 작업 시간
int inDegree[MAX_N + 1]; // 진입 차수
vector<int> g[MAX_N + 1]; // 선행 관계를 나타내는 그래프
int maxT[MAX_N + 1]; // 작업이 완료되기까지의 최대 시간
int ans;


void solve() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int nxt : g[curr]) {
			inDegree[nxt]--;
			if (inDegree[nxt] == 0) q.push(nxt);

			maxT[nxt] = max(maxT[nxt], maxT[curr] + wt[nxt]);
		}
	}

	for (int i = 1; i <= N; i++) {
		ans = max(ans, maxT[i]);
	}
	return;
}
int main() {
	cin >> N;

	int cnt, u;
	for (int i = 1; i <= N; i++) {
		cin >> wt[i] >> cnt;

		maxT[i] = wt[i];
		
		for (int j = 0; j < cnt; j++) {
			cin >> u;
			g[u].push_back(i);
			inDegree[i]++;
		}
	}
	
	solve();

	cout << ans;

	return 0;
}