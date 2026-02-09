#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 200000

using namespace std;

int N;
pair<int, int> arr[MAX_N]; // {컵라면 수, 데드라인}
int ans;

bool comp(pair<int, int>& a, pair<int, int>& b) { // 데드라인 작은 순
	return a.second < b.second;
}

void solve() {
	sort(arr, arr + N, comp);

	priority_queue<pair<int, int>> pq;

	int t = arr[N - 1].second + 1;
	int idx = N - 1;

	while (--t) {
		while (idx >= 0 && arr[idx].second >= t) pq.push(arr[idx--]);
		
		if (!pq.empty()) {
			ans += pq.top().first;
			pq.pop();
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].second >> arr[i].first;
	}

	solve();

	cout << ans;

	return 0;
}