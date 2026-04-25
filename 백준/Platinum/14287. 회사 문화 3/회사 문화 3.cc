#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

int N, M;
int tree[4 * MAX_N];

int cnt;
int in[MAX_N + 1], out[MAX_N + 1];
vector<int> g[MAX_N + 1];

void dfs(int curr) {
	in[curr] = ++cnt;
	for (int nxt : g[curr]) dfs(nxt);
	out[curr] = cnt;
	return;
}

void update(int node, int l, int r, int q, int val) {
	if (l == r) {
		tree[node] += val;
		return;
	}

	int mid = (l + r) >> 1;
	if (q <= mid) update(node << 1, l, mid, q, val);
	else update((node << 1) | 1, mid + 1, r, q, val);

	tree[node] = tree[node << 1] + tree[(node << 1) | 1];

	return;
}
int query(int node, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return tree[node];

	int mid = (l + r) >> 1;

	return query(node << 1, l, mid, ql, qr) + query((node << 1) | 1, mid + 1, r, ql, qr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;

	int parent;
	cin >> parent;
	for (int i = 2; i <= N; i++) {
		cin >> parent;
		g[parent].push_back(i);
	}

	dfs(1);

	int comm, a, w;
	for (int i = 0; i < M; i++) {
		cin >> comm;
		if (comm == 1) {
			cin >> a >> w;
			update(1, 1, N, in[a], w);
		}
		else {
			cin >> a;
			cout << query(1, 1, N, in[a], out[a]) << '\n';
		}
	}

	return 0;
}