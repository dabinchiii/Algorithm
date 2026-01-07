#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10000

using namespace std;

struct node {
	int w, u, v;
};

int N, P;
int parent[MAX_N + 1], nodeW[MAX_N + 1];
int minW;
vector<node> edges;
int ans;

bool cmp(const node& a, const node& b) {
	return a.w < b.w;
}

void makeSet() {
	for (int i = 1; i <= N; i++) parent[i] = i;
}
int findRoot(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findRoot(parent[x]);
}
bool makeUnion(int a, int b) {
	int rootA = findRoot(a);
	int rootB = findRoot(b);

	if (rootA == rootB) return false;

	parent[rootA] = rootB;

	return true;
}

void solve() {
	int cnt = 0;

	sort(edges.begin(), edges.end(), cmp);

	makeSet();

	for (auto& curr : edges) {
		if (makeUnion(curr.u, curr.v)) {
			ans += curr.w;
			++cnt;
		}
	}

	ans += minW;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> P;

	minW = 1001;
	for (int i = 1; i <= N; i++) {
		cin >> nodeW[i];
		minW = min(minW, nodeW[i]);
	}

	int s, e, l;
	for (int i = 0; i < P; i++) {
		cin >> s >> e >> l;
		edges.push_back({ (l << 1) + nodeW[s] + nodeW[e], s, e});
	}

	solve();

	cout << ans;

	return 0;
}