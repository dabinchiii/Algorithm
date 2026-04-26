#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N, M;
int arr[MAX_N + 1];
vector<int> tree[4 * MAX_N];

void makeTree(int node, int l, int r) {
	if (l == r) {
		tree[node] = { arr[l] };
		return;
	}

	int mid = (l + r) >> 1;
	int lc = node << 1;
	int rc = lc | 1;

	makeTree(lc, l, mid);
	makeTree(rc, mid + 1, r);

	merge(tree[lc].begin(), tree[lc].end(), tree[rc].begin(), tree[rc].end(), back_inserter(tree[node]));

	return;
}

int query(int node, int l, int r, int ql, int qr, int k) {
	if (l > qr || r < ql) return 0;

	if (l >= ql && r <= qr) {
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	}

	int mid = (l + r) >> 1;

	return query(node << 1, l, mid, ql, qr, k) + query((node << 1) | 1, mid + 1, r, ql, qr, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	makeTree(1, 1, N);

	cin >> M;

	int a, b, k;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> k;
		cout << query(1, 1, N, a, b, k) << '\n';
	}

	return 0;
}