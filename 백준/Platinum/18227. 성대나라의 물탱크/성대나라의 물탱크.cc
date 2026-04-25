#include <iostream>
#include <vector>

#define MAX_N 200000

using namespace std;

int N, Q;
int root;
long long tree[4 * MAX_N];

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

void update(int node, int l, int r, int q) {
	if (l == r) {
		++tree[node];
		return;
	}

	int mid = (l + r) >> 1;
	if(q <= mid) update(node << 1, l, mid, q);
	else update((node << 1) | 1, mid + 1, r, q);

	tree[node] = tree[node << 1] + tree[(node << 1) | 1];

	return;
}
long long query(int node, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return tree[node];

	int mid = (l + r) >> 1;
	return query(node << 1, l, mid, ql, qr) + query((node << 1) | 1, mid + 1, r, ql, qr);
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
		if (comm == 1) update(1, 1, N, in[a]);
		else cout << depth[a] * query(1, 1, N, in[a], out[a]) << '\n';
	}
	return 0;
}