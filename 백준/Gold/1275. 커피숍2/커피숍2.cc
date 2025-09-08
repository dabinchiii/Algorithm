#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int N, Q;
int arr[100001];
ll *tree;

void makeTree(int node, int start, int end) {
	if (start == end) { // 리프
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	makeTree(2 * node, start, mid);
	makeTree(2 * node + 1, mid + 1, end);

	tree[node] = tree[2 * node] + tree[2 * node + 1];

	return;
}

ll sum(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0; // 아예 포함되지 않음

	if (start >= left && end <= right) return tree[node]; // 완전히 포함됨

	int mid = (start + end) / 2;
	ll leftSum = sum(2 * node, start, mid, left, right);
	ll rightSum = sum(2 * node + 1, mid + 1, end, left, right);

	return leftSum + rightSum;
}

void update(int node, int start, int end, int idx, ll value) {
	if (start > idx || end < idx) return; // 아예 포함되지 않음

	if (start == end) {
		if (start == idx) tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	if (idx >= start && idx <= mid) update(2 * node, start, mid, idx, value);
	if (idx > mid && idx <= end) update(2 * node + 1, mid + 1, end, idx, value);
	tree[node] = tree[2 * node] + tree[2 * node + 1];

	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> Q;
	
	for (int i = 1; i <= N; i++) cin >> arr[i];

	int h = ceil(log2(N)) + 1;
	tree = new ll[1 << h];

	makeTree(1, 1, N);

	int x, y, a;
	ll b;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;

		if (x > y) swap(x, y);

		printf("%ld\n", sum(1, 1, N, x, y));
		update(1, 1, N, a, b);
	}
	return 0;
}