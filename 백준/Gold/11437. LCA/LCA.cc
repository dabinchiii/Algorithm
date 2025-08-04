#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 50001

using namespace std;

int n, m;
vector<int> g[MAX_N];
vector<int> parent(MAX_N);
int ans;

int lca(int a, int b) {
	vector<bool> visited(n + 1, false);

	int curr = a;
	while (curr != -1) {
		visited[curr] = true;
		curr = parent[curr];
	}

	curr = b;
	while (curr != -1) {
		if (visited[curr]) {
			return curr;
		}
		curr = parent[curr];
	}

	return -1;
}

void findParent() {
	queue<int> q;
	vector<bool> visited(n + 1, false);

	q.push(1);
	visited[1] = true;
	parent[1] = -1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int nxt : g[curr]) {
			if (visited[nxt]) continue;

			q.push(nxt);
			visited[nxt] = true;
			parent[nxt] = curr;
		}
	}
	return;
}
int main()
{
	cin >> n;
	
	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	findParent();

	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		int ans = lca(a, b);
		cout << ans << '\n';
	}

	return 0;
}