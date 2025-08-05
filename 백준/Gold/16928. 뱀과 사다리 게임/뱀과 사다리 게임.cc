#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int n, m;
map<int, int> portal;
int ans;

void solve() {
	queue<pair<int, int>> q;
	vector<bool> visited(101, false);

	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		int currX = q.front().first;
		int currCnt = q.front().second;
		q.pop();

		if (currX == 100) {
			ans = currCnt;
			return;
		}

		for (int i = 1; i <= 6; i++) { // 주사위
			int nxtX = currX + i;
			if (portal[nxtX]) {
				nxtX = portal[nxtX];
			}

			if (nxtX > 100) continue;
			if (visited[nxtX]) continue;

			q.push({ nxtX, currCnt + 1 });
			visited[nxtX] = true;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n + m; i++) {
		cin >> x >> y;
		portal[x] = y;
	}
	solve();
	cout << ans;
	return 0;
}