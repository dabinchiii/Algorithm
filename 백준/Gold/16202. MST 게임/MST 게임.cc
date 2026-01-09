#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000
#define MAX_M 10000

using namespace std;

struct edge {
	int u, v;
	bool isDead;
};

int N, M, K;
int parent[MAX_N + 1];
vector<edge> edges(MAX_M + 1);
int first;

void makeSet() {
	for (int i = 1; i <= N; i++) parent[i] = i;
	return;
}
int findRoot(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findRoot(parent[x]);
}
bool makeUnion(int a, int b) {
	int rootA = findRoot(a), rootB = findRoot(b);
	if (rootA == rootB) return false;
	parent[rootA] = rootB;
	return true;
}

int mst() {
	int cnt = 0, cost = 0;

	makeSet();

	first = -1;
	for (int i = 1; i <= M && cnt < N - 1; i++) {
		auto& curr = edges[i];

		if (curr.isDead) continue;
		
		if (makeUnion(curr.u, curr.v)) {
			++cnt;
			cost += i;
			if (first == -1) first = i;
		}
	}
	
	return cnt < N - 1 ? 0 : cost;
}
void solve() {
	int cost = -1;
	
	for (int i = 0; i < K; i++) {
		if (cost != 0) {
			edges[first].isDead = true;
			cost = mst();
		}
		cout << cost << ' ';
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= M; i++) {
		cin >> edges[i].u >> edges[i].v;
		edges[i].isDead = false;
	}

	solve();

	return 0;
}