#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 500000

using namespace std;

int N, M;
int arr[MAX_N + 1]; // 초기 월급
int tree[4 * MAX_N];

int cnt;
int in[MAX_N + 1], out[MAX_N + 1];
unordered_map<int, int> inToIdx;
vector<int> g[MAX_N + 1];


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
int query(int node, int l, int r, int q) {
	if (l == r) return tree[node];

	int mid = (l + r) >> 1;
	int res = tree[node];
	if (q <= mid) res += query(node << 1, l, mid, q);
	else res += query((node << 1) + 1, mid + 1, r, q);

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int parent;
	cin >> arr[1];
	for (int i = 2; i <= N; i++) {
		cin >> arr[i] >> parent;
		g[parent].push_back(i);
	}

	dfs(1);
	for (int i = 1; i <= N; i++) inToIdx[in[i]] = i;

	char comm;
	int a, x;
	for (int i = 0; i < M; i++) {
		cin >> comm;
		if (comm == 'p') {
			cin >> a >> x;
			update(1, 1, N, in[a] + 1, out[a], x);
		}
		else {
			cin >> a;
			cout << arr[a] + query(1, 1, N, in[a]) << '\n';
		}
	}

	return 0;
}