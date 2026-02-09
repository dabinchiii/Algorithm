#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> arr;
int ans;

void solve() {
	sort(arr.begin(), arr.end());

	priority_queue<pair<int, int>> pq;

	int t = arr[N - 1].first;
	int idx = N - 1;

	while (t) {
		while (idx >= 0 && arr[idx].first >= t) {
			pq.push({arr[idx].second, arr[idx].first});
			idx--;
		}

		if (!pq.empty()) {
			ans += pq.top().first;
			pq.pop();
		}

		t--;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int d, c;
	for (int i = 0; i < N; i++) {
		cin >> d >> c;
		arr.push_back({ d, c });
	}

	solve();

	cout << ans;

	return 0;
}