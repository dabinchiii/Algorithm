#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

int N, M;
int tree[2 * MAX_N + 5];

int cnt;
int in[MAX_N + 1], out[MAX_N + 1];
vector<int> g[MAX_N + 1];

void dfs(int curr) {
	in[curr] = ++cnt;
	for (int nxt : g[curr]) dfs(nxt);
	out[curr] = cnt;
	return;
}

void update(int q, int val) {
	for (tree[q += N] += val; q > 1; q >>= 1) {
		tree[q >> 1] = tree[q] + tree[q ^ 1];
	}
	return;
}
int query(int l, int r) {
	int res = 0;
	for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += tree[l++];
		if (r & 1) res += tree[--r];
	}
	return res;
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
			update(in[a], w);
		}
		else {
			cin >> a;
			cout << query(in[a], out[a]) << '\n';
		}
	}

	return 0;
}