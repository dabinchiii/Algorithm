#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct loc {
	int r, c;
};
int n, m;
int board[50][50];
int ans;

vector<loc> virus;
int cntVirus;
int cntBlank;

int arr[10];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool isValid(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}
void bfs() {
	queue<pair<loc, int>> q;
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	for (int i = 0; i < m; i++) {
		loc v = virus[arr[i]];
		q.push({ v, 0 });
		visited[v.r][v.c] = true;
	}

	int currBlank = cntBlank;
	if (currBlank == 0) {
		ans = 0;
		return;
	}
	while (!q.empty()) {
		int r = q.front().first.r;
		int c = q.front().first.c;
		int t = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			int nt = t + 1;

			if (!isValid(nr, nc)) continue;
			if (board[nr][nc] == 1) continue;
			if (visited[nr][nc]) continue;

			q.push({ {nr, nc}, nt });
			visited[nr][nc] = true;
			currBlank--;

			if (currBlank == 0) {
				ans = min(ans, nt);
				return;
			}
		}
	}
}
void dfs(int cnt, int start) {
	if (cnt == m) {
		bfs();
		return;
	}

	for (int i = start; i < cntVirus; i++) {
		arr[cnt] = i;

		dfs(cnt + 1, i + 1);
	}
	return;
}
void solve() {
	ans = 1000000;
	dfs(0, 0);
	if (ans == 1000000) ans = -1;
	return;
}
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i, j });
			}
			else if (board[i][j] == 0) {
				cntBlank++;
			}
		}
	}
	
	cntVirus = virus.size();
	cntBlank += cntVirus - m;

	solve();

	cout << ans;

	return 0;
}