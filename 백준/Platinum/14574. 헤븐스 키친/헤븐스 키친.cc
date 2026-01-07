#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_N 10000

using namespace std;

struct node {
	long long w;
	int curr, prev;

	bool operator<(const node& other) const {
		return w < other.w;
	}
};

int N;
long long P[MAX_N + 1], C[MAX_N];
bool visited[MAX_N + 1];
vector<int> g[MAX_N + 1];
long long ansSum;

long long getCost(int a, int b) {
	return (C[a] + C[b]) / abs(P[a] - P[b]);
}

void dfs(int curr, int parent) {
	for (int nxt : g[curr]) {
		if (nxt == parent) continue;
		
		dfs(nxt, curr);

		cout << curr << ' ' << nxt << '\n';
	}
}
void solve() {
	priority_queue<node> pq;
	int cnt = 0;
	int root = 1;

	pq.push({ 0, root, -1 });

	while (!pq.empty() && cnt < N) {
		long long currW = pq.top().w;
		int currV = pq.top().curr;
		int prevV = pq.top().prev;
		pq.pop();

		if (visited[currV]) continue;

		visited[currV] = true;
		ansSum += currW;
		if (prevV != -1) {
			g[prevV].push_back(currV);
			g[currV].push_back(prevV);
		}
		++cnt;

		//printf("currW: %d, (%d, %d)\n", currW, prevV, currV);

		for (int i = 1; i <= N; i++) {
			if (currV == i || visited[i]) continue;
			pq.push({ getCost(currV, i), i, currV});
		}
	}

	cout << ansSum << '\n';
	dfs(root, -1);

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i] >> C[i];
	}

	solve();

	return 0;
}