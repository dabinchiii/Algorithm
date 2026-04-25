#include <iostream>
#include <vector>

#define MAX_N 200000

using namespace std;

int N, Q;
int root;
long long tree[2 * MAX_N + 5];

int cnt;
int in[MAX_N + 1], out[MAX_N + 1], depth[MAX_N + 1];
vector<int> g[MAX_N + 1];

void dfs(int curr, int parent) {
	in[curr] = ++cnt;
	for (int nxt : g[curr]) {
		if (nxt != parent) {
			depth[nxt] = depth[curr] + 1;
			dfs(nxt, curr);
		}
	}
	out[curr] = cnt;
	return;
}

void update(int q) {
	for (tree[q += N] += 1; q > 1; q >>= 1) {
		tree[q >> 1] = tree[q] + tree[q ^ 1];
	}
	return;
}
long long query(int l, int r) {
	long long res = 0;
	for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += tree[l++];
		if (r & 1) res += tree[--r];
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> root;

	int x, y;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	depth[root] = 1;
	dfs(root, -1);

	cin >> Q;
	int comm, a;
	while (Q--) {
		cin >> comm >> a;
		if (comm == 1) update(in[a]);
		else cout << depth[a] * query(in[a], out[a]) << '\n';
	}
	return 0;
}