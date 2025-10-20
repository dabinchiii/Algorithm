#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100000

using namespace std;

int N;
vector<int> g[MAX_N + 1];
bool visited[MAX_N + 1];
int ans;

void solve() {
	queue<pair<int, int>> q;

	q.push({ 1, 0 });
	visited[1] = true;

	int maxD = -1, maxV = -1;
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		if (curr.second > maxD) {
			maxD = curr.second;
			maxV = curr.first;
		}

		for (int nxt : g[curr.first]) {
			if (visited[nxt]) continue;

			q.push({ nxt, curr.second + 1 });
			visited[nxt] = true;
		}
	}

	for (int i = 1; i <= N; i++) visited[i] = false;

	q.push({ maxV, 0 });
	visited[maxV] = true;

	maxD = -1;
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		if (curr.second > maxD) {
			maxD = curr.second;
		}

		for (int nxt : g[curr.first]) {
			if (visited[nxt]) continue;

			q.push({ nxt, curr.second + 1 });
			visited[nxt] = true;
		}
	}

	ans = (maxD + 1) / 2;

	return;
}

int main() {
	cin >> N;

	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	solve();

	cout << ans;

	return 0;
}