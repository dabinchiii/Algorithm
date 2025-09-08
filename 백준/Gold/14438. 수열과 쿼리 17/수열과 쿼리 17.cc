#include <iostream>
#include <cmath>

#define INF 1000000001

using namespace std;

struct treeNode {
	int idx, value;
};

int N, M;
int arr[100001];
treeNode *tree;

void makeTree(int node, int start, int end) {
	if (start == end) { // 리프
		tree[node] = { start, arr[start] };
		return;
	}

	int mid = (start + end) / 2;
	makeTree(2 * node, start, mid);
	makeTree(2 * node + 1, mid + 1, end);
	tree[node] = (tree[2 * node].value <= tree[2 * node + 1].value ? tree[2 * node] : tree[2 * node + 1]);

	return;
}

void update(int node, int start, int end, int idx, int value) {
	if (start > idx || end < idx) return; // 아예 포함되지 않음 => 업데이트 X

	if (start == end) {
		if (start == idx) tree[node].value = value;
		return;
	}

	int mid = (start + end) / 2;
	if (idx >= start && idx <= mid) update(2 * node, start, mid, idx, value);
	if (idx > mid && idx <= end) update(2 * node + 1, mid + 1, end, idx, value);

	tree[node] = (tree[2 * node].value <= tree[2 * node + 1].value ? tree[2 * node] : tree[2 * node + 1]);

	return;
}

treeNode getMin(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return { 0, INF }; // 범위에 아예 포함되지 X

	if (start >= left && end <= right) return tree[node]; // 범위에 완전히 포함됨

	int mid = (start + end) / 2;
	treeNode leftMin = getMin(2 * node, start, mid, left, right);
	treeNode rightMin = getMin(2 * node + 1, mid + 1, end, left, right);

	return (leftMin.value <= rightMin.value ? leftMin : rightMin);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	int h = ceil(log2(N)) + 1;
	tree = new treeNode[1 << h];

	makeTree(1, 1, N);

	cin >> M;

	int q, a, b;
	for (int i = 0; i < M; i++) {
		cin >> q >> a >> b;

		if (q == 1) { // 1 i v : Ai를 v로 바꾼다.
			update(1, 1, N, a, b);
		}
		else { // 2 i j : Ai, Ai+1, ..., Aj에서 크기가 가장 작은 값의 인덱스를 출력한다.
			cout << getMin(1, 1, N, a, b).value << '\n';
		}
	}

	return 0;
}
