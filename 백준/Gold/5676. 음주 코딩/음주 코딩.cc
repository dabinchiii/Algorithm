#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int N, P;
int arr[100001];
int *tree;

void makeTree(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	makeTree(2 * node, start, mid);
	makeTree(2 * node + 1, mid + 1, end);

	tree[node] = tree[2 * node] * tree[2 * node + 1];

	return;
}
void update(int node, int start, int end, int idx, int value) {
	if (start > idx || end < idx) return; // 아예 범위에 포함되지 X
	if (start == end) {
		if (start == idx) tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	if (idx >= start && idx <= mid) update(2 * node, start, mid, idx, value);
	if (idx > mid && idx <= end) update(2 * node + 1, mid + 1, end, idx, value);

	tree[node] = tree[2 * node] * tree[2 * node + 1];

	return;
}

int getP(int node, int start, int end, int left, int right) { // 리턴값: -1, 0, 1
	if (start > right || end < left) return 1; // 아예 범위에 포함되지 X
	if (start >= left && end <= right) return tree[node]; // 범위에 완전히 포함됨

	int mid = (start + end) / 2;
	int leftP = getP(2 * node, start, mid, left, right);
	int rightP = getP(2 * node + 1, mid + 1, end, left, right);

	return leftP * rightP;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> N >> P) {
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			arr[i] = (arr[i] > 0 ? 1 : (arr[i] < 0 ? -1 : 0));
		}

		int h = ceil(log2(N)) + 1;
		tree = new int[1 << h];
		makeTree(1, 1, N);

		char q;
		int a, b;
		string ans = "";
		for (int i = 0; i < P; i++) {
			cin >> q >> a >> b;
			if (q == 'C') {
				b = (b > 0 ? 1 : (b < 0 ? -1 : 0));
				update(1, 1, N, a, b);
			}
			else {
				int res = getP(1, 1, N, a, b);
				if (res == 0) ans += '0';
				else ans += (res > 0 ? '+' : '-');
			}
		}

		cout << ans << '\n';
	}

	return 0;
}