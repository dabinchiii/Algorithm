#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 200000

using namespace std;

int n, k;
int ansT;
vector<int> ansPath;

void solve() {
	queue<pair<int, int>> q;
	vector<bool> visited(MAX, false);
	vector<int> before(MAX, -1);

	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();

		if (x == k) {
			ansT = t;

			int curr = k;
			while (curr != -1) {
				ansPath.push_back(curr);
				curr = before[curr];
			}
			reverse(ansPath.begin(), ansPath.end());

			return;
		}

		int nx, nt = t + 1;
		nx = x + 1;
		if (nx < MAX && !visited[nx]) {
			q.push({ nx, nt });
			visited[nx] = true;
			before[nx] = x;
		}

		nx = x - 1;
		if (nx >= 0 && !visited[nx]) {
			q.push({ nx, nt });
			visited[nx] = true;
			before[nx] = x;
		}
		
		nx = 2 * x;
		if (nx < MAX && !visited[nx]) {
			q.push({ nx, nt });
			visited[nx] = true;
			before[nx] = x;
		}
	}
	return;
}
int main() {
	cin >> n >> k;

	solve();

	cout << ansT << '\n';
	for (int curr : ansPath) {
		cout << curr << " ";
	}
	return 0;
}