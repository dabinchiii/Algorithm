#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 500
using namespace std;

int n, m;
vector<int> taller[MAX_N + 1];
vector<int> shorter[MAX_N + 1];
int ans;

int q[MAX_N + 1];
int head, tail;

void check(int target) {
	head = tail = 0;
	vector<bool> visited(n + 1, false);
	int cnt = 0;

	//q.push(target);
	q[tail++] = target;
	visited[target] = true;

	while (head != tail) {
		//int curr = q.front();
		//q.pop();
		int curr = q[head++];

		for (int nxt : taller[curr]) {
			if (!visited[nxt]) {
				visited[nxt] = true;
				cnt++;
				//q.push(nxt);
				q[tail++] = nxt;
			}
		}
	}

	head = tail = 0;
	//q.push(target);
	q[tail++] = target;
	while (head != tail) {
		//int curr = q.front();
		//q.pop();
		int curr = q[head++];

		for (int nxt : shorter[curr]) {
			if (!visited[nxt]) {
				visited[nxt] = true;
				cnt++;
				//q.push(nxt);
				q[tail++] = nxt;
			}
		}
	}

	if (cnt == n - 1) ans++;
}

void solve() {
	ans = 0;
	for (int i = 1; i <= n; i++) {
		check(i);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//int T;
	//cin >> T;
	//for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			taller[i].clear();
			shorter[i].clear();
		}

		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			taller[a].push_back(b);
			shorter[b].push_back(a);
		}

		solve();

		//cout << "#" << tc << " " << ans << '\n';
		cout << ans;
	//}
	

	return 0;
}
