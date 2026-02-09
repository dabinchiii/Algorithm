#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 200000

using namespace std;

int N;
vector<int> ts[MAX_N + 1];
int ans;

void solve() {
	priority_queue<int> pq;
	for (int t = MAX_N; t > 0; t--) {
		for (int curr : ts[t]) pq.push(curr);
		

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
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
		ts[d].push_back(c);
	}

	solve();

	cout << ans;

	return 0;
}