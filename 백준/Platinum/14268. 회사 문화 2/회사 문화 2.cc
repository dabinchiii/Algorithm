#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

int N, M;
vector<int> g[MAX_N + 1];
int cnt;
int in[MAX_N + 1], out[MAX_N + 1];
long long tree[4 * MAX_N];

void dfs(int curr) { // 오일러 경로 생성
	in[curr] = ++cnt;
	for (int nxt : g[curr]) dfs(nxt);
	out[curr] = cnt;
	return;
}

void update(int node, int l, int r, int ql, int qr, int val) {
	if (l > qr || r < ql) return;

	if (l >= ql && r <= qr) {
		tree[node] += val;
		return;
	}

	int mid = (l + r) >> 1;
	update(node << 1, l, mid, ql, qr, val);
	update((node << 1) + 1, mid + 1, r, ql, qr, val);

	return;
}
long long query(int node, int l, int r, int q) {
	if (l == r) return tree[node];

	int mid = (l + r) >> 1;
	long long res = tree[node];
	if (q <= mid) res += query(node << 1, l, mid, q);
	else res += query((node << 1) + 1, mid + 1, r, q);

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
	// in[] 값 기준으로 정렬하여 펼쳐진 1차원으로 생각

	int comm, a, w;
	for (int i = 0; i < M; i++) {
		cin >> comm;
		if (comm == 1) {
			cin >> a >> w;
			update(1, 1, N, in[a], out[a], w);
		}
		else {
			cin >> a;
			cout << query(1, 1, N, in[a]) << '\n';
		}
	}

	return 0;
}